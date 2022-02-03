#include <iostream>
#include <map>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n;
    std::cin >> n;

    std::map<int, int> map;
    long long br = 0;
    long long cnt = 0;
    map[0]++;
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        br += num;
        cnt += map[(br % n + n) % n];
        map[(br % n + n) % n]++;
    }
    std::cout << cnt << "\n";
}