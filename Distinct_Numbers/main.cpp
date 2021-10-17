#include <iostream>
#include <set>

int main() {
    int n;
    std::cin >> n;
    std::set<int> set;

    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        set.insert(num);
    }

    std::cout << set.size() << std::endl;
    return 0;
}
