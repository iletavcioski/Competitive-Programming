#include <iostream>
#include <vector>
#include <string>
#include <map>
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();
 
    int n;
    std::cin >> n;
    if (n % 10 == 0) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << 10 - (n % 10) << "\n";
    }
    return 0;
}