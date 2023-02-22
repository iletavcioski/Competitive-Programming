#include <iostream>
#include <vector>


int n;
int fenwick_tree[350001];

void update(int x, int value) {
    int i = x;
    while (i <= n) {
        fenwick_tree[i] += value;
        i += (i & (-i));
    }
}

int query(int x) {
    int i = x - 1;
    int result = 0;
    while (i) {
        result += fenwick_tree[i];
        i -= (i & (-i));
    }
    return result;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();


    std::cin >> n;
    std::vector<int> linked_list(n + 1, -1);

    int first = -1;
    int last = -1;
    for (int i = 1; i <= n; i++) {
        char query;
        int ordinal_number;
        std::cin >> query;
        if (i == 1) {
            first = 1;
            last = 1;
            continue;
        }

        if (query == 'K') {
            linked_list[i] = last;
            last = i;
        } else {
            std::cin >> ordinal_number;
            if (ordinal_number == first) {
                first = i;
                linked_list[ordinal_number] = i;
            } else {
                linked_list[i] = linked_list[ordinal_number];
                linked_list[ordinal_number] = i;
            }
        }
    }

    std::vector<int> order_of_customers;
    order_of_customers.push_back(last);
    while (linked_list[last] != -1) {
        order_of_customers.push_back(linked_list[last]);
        last = linked_list[last];
    }


    std::vector<int> solution(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        solution[order_of_customers[i]] = query(order_of_customers[i]);
        update(order_of_customers[i], 1);
    }


    for (int i = 1; i <= n; i++) {
        std::cout << solution[i] + 1 << '\n';
    }


    return 0;
}