#include <iostream>
#include <map>
int main() {
    int n;
    long long x;
    std::cin >> n >> x;

    std::map<long long, int> map;
    map[0] = 1;
    long long sum = 0;
    long long count = 0;
    for (int i = 0; i < n; i++) {
        long long number;
        std::cin >> number;
        sum += number;
        count += map[sum - x];
        map[sum]++;
    }
    std::cout << count << std::endl;
    return 0;
}
