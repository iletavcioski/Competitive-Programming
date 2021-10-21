#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> array;
    array.resize(n);

    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    std::sort(array.begin(), array.end());

    int mid = n / 2;
    int middle_num;
    if (n % 2 == 0) {
        middle_num = array[mid] + array[mid - 1];
        middle_num /= 2;
    } else {
        middle_num = array[mid];
    }

    long long count = 0;

    for (int i = 0; i < n; i++) {
        count += std::abs(array[i] - middle_num);
    }
    std::cout << count << std::endl;
    return 0;
}
