#include <iostream>
#include <map>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, x;
    std::cin >> n >> x;
    std::map<int, int> map;
    std::vector<int> array;
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        map[num] = i + 1;
        array.emplace_back(num);
    }

    for (int i = 0; i < n; i++) {
        if (map[x - array[i]] && map[x - array[i]] != i + 1) {
            std::cout << map[x - array[i]] << " " << i + 1 << std::endl;
            return 0;
        }
    }
    std::cout << "IMPOSSIBLE" << std::endl;
    return 0;
}
