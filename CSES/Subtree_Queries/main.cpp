#include <iostream>
#include <vector>

std::vector<std::vector<int> > tree;
std::vector<long long> array;
std::vector<std::pair<int, int> > map(200002, {-1, -1});
std::vector<long long> tree_values;

void dfs(int cur, int prev) {
    array.push_back(tree_values[cur]);
    map[cur].first = int(array.size() - 1);
    for (int following : tree[cur]) {
        if (following != prev) {
            dfs(following, cur);
        }
    }
    array.push_back(tree_values[cur]);
    map[cur].second = int(array.size() - 1);

}

template<typename T>
class node {
    public:
    node* left;
    node* right;
    T value;
    
    node() {
        this->left = NULL;
        this->right = NULL;
        this->value = 0;
    }
};

template<typename T>
class segmentTree {
    public:
    node<T>* root;
    std::vector<T> numbers;

    segmentTree(node<T>* root, std::vector<T>* numbers) {
        this->root = root;
        this->numbers = *numbers;
    }

    void build(node<T>* current_node, int left, int right) {
        if (left == right) {
            current_node->value = this->numbers[left];
        }

        current_node->left = new node<T>();
        current_node->right = new node<T>();
        build(current_node->left, left, (left + right) / 2);
        build(current_node->right, (left + right) / 2 + 1, right);
        current_node->value = current_node->left->value + current_node->right->value;
    }

    void update(node<T>* current_node, int position, int value, int left, int right) {
        if (position > right || position < left) {
            return;
        }

        if (left == right) {
            current_node->value = value;
            return;
        }

        update(current_node->left, position, value, left, (left + right) / 2);
        update(current_node->right, position, value, (left + right) / 2 + 1, right);
    }

    T query(node<T>* current_node, int left_range, int right_range, int left, int right) {
        if (left > right_range or right < left_range) {
            return 0;
        }

        if (left >= left_range and right <= right_range) {
            return current_node->value;
        }

        return query(current_node->left, left_range, right_range, left, (left + right) / 2) + query(current_node->right, left_range, right_range, (left + right) / 2 + 1, right);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, q;
    std::cin >> n >> q;

    
    tree_values.resize(n);
    std::vector<int> vec;
    tree.insert(tree.begin(), n, vec);

    for (int i = 0; i < n; i++) {
        std::cin >> tree_values[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(0, -1);
    int sz = tree_values.size();
    auto *root = new node<long long>();
    auto *obj = new segmentTree<long long>(root, &tree_values);
    obj->build(obj->root, 0, sz - 1);

    for (int i = 0; i < q; i++) {
        int t;
        std::cin >> t;

        if (t == 1) {
            int s, value;
            std::cin >> s >> value;
            s--;

            obj->update(obj->root, map[s].first, value, 0, sz - 1);
            obj->update(obj->root, map[s].second, value, 0, sz - 1);
        } else {
            int s;
            std::cin >> s;
            s--;
            std::cout << obj->query(obj->root, map[s].first, map[s].second, 0, sz - 1) << "\n";
        }
    }

    return 0;
}