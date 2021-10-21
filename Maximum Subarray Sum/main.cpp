#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n;
    std::cin >> n;

    long long count = 0;
    long long max = -1e9;


    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        count += num;
        max = std::max(max, count);
        if (count < 0) {
            count = 0;
        }
    }

    std::cout << max << std::endl;

    return 0;
}
