#include <iostream>
#include <vector>
#include <algorithm>


int main() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> array;
    array.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    std::sort(array.begin(), array.end());
    std::reverse(array.begin(), array.end());
    int last = array.size() - 1;
    long long weight = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        weight = 0;
        if (last < i) break;
        weight += array[i];
        if (last > i && weight + array[last] <= x) {
            last--;
        }
        count++;
    }

    std::cout << count << std::endl;
    return 0;
}
