#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    long long k;
    std::cin >> k;

    long long prevpoc = 0;
    long long poc = 0;
    long long n = 0;
    while (poc * n <= k) {
        prevpoc = poc;
        poc *= 10;
        poc += 9;
        n++;
    }
    n--;
    poc = prevpoc;
    k -= 

    return 0;
}