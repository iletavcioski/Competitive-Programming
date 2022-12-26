#include <iostream>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int t;
    std::cin >> t;

    while (t--) {
        long long k;
        std::cin >> k;
        
        long long start = 9;
        long long length = 1;

        long long prev_start = 0;
        while (start * length <= k) {
            k -= start * length;
            prev_start += start;
            length++;
            start *= 10;
        }

        long long num = prev_start + (k / length);
        if (k % length) {
            num++;
        } else {
            std::cout << num % 10 << std::endl;
            continue;
        }

        long long num1 = pow(10LL, (length - (k % length)));
        num /= num1;
        std::cout << num % 10 << std::endl;
    }

    return 0;
}