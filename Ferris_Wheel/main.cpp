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
    long long weight = 0;
    int count = 1;

    for (int child : array) {
        if (weight + child <= x) {
            weight += child;
        } else {
            count++;
            weight = child;
        }
    }

    std::cout << count << std::endl;
    return 0;
}
