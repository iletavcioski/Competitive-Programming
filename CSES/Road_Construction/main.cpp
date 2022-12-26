#include <iostream>
#include <vector>
#include <queue>

std::vector<int> parent(100001, -1);

int find(int x) {
    if (parent[x] == -1) {
        return x;
    } else {
        return find(parent[x]);
    }
}

void set_parent(int x, int _parent) {
    if (parent[x] == -1) {
        return;
    } else if (x != _parent) {
        int next = parent[x];
        parent[x] = _parent;
        return set_parent(next, _parent);
    }
} 

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, m;
    std::cin >> n >> m;


    int num = n;
    std::vector<int> size(n + 1, 1);
    int max = 1;
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        
        
        int parent_a = find(a);
        int parent_b = find(b);

        //std::cout << parent_a << " <--> " << parent_b << "\n";

        if (parent_a != parent_b) {
            num--;
            int new_parent = std::min(parent_a, parent_b);
            if (new_parent != parent_a) {
                parent[parent_a] = new_parent;
                size[new_parent] += size[parent_a];
            } else {
                parent[parent_b] = new_parent;
                size[new_parent] += size[parent_b];
            }

            max = std::max(max, size[new_parent]);
            
            set_parent(a, new_parent);
            set_parent(b, new_parent);
        }

        std::cout << num << " " << max << "\n";
    }

    return 0;
}