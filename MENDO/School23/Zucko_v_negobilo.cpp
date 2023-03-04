#include <iostream>
#include <vector>
#include <string>
#include <map>
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();
 
    long long n;
    std::cin >> n;
 
    if (n == 1) {
        std::cout << 1 << std::endl;
        return 0;
    }
    n-=2;
    long long ost = n % 4;
    long long res = (n / 4) * 20 + 2;
 
    if (ost == 1) {
        res += 2;
    } else if (ost == 2) {
        res += 6;
    } else if (ost == 3) {
        res += 14;
    }
    std::cout << res << std::endl;
    return 0;
}