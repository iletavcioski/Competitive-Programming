#include <iostream>
#include <map>

int main() {
    int n;
    long long x;
    std::cin >> n >> x;
    std::map<long long, int> map;
    long long count = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        long long number;
        sum += number;
        map[sum]++;
    }
    return 0;
}
