#include <iostream>

long long N;

void read() {
    std::cin >> N;
}

void solve(long long n) {
    std::cout << n;
    while (n > 1) {
        if (n % 2) {
            n = n * 3 + 1;
        } else {
            n /= 2;
        }
        std::cout << " " << n;
    }
    std::cout << std::endl;
}

int main() {
    read();
    solve(N);
    return 0;
}
