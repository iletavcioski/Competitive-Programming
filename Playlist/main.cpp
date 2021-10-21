#include <iostream>
#include <vector>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n;
    std::cin >> n;
    int max = 0;
    int cnt = 0;
    std::map<int, int> map;
    int first = 0;
    std::vector<int> array;
    array.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
        map[array[i]]++;
        if (map[array[i]] == 2) {
            while (map[array[i]] == 2) {
                map[array[first]]--;
                if (map[array[first]] == 0) {
                    cnt--;
                }
                first++;
            }
            max = std::max(cnt, max);
        } else {
            cnt++;
            max = std::max(cnt, max);
        }
    }
    std::cout << max << std::endl;
    return 0;
}
