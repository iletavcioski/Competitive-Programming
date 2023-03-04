#include <iostream>
#include <vector>
#include <string>
#include <map>
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();
 
    int a, b;
    std::cin >> a >> b;
     
    std::cout << std::min(std::min(a, b), (std::max(a, b) - std::min(a, b)) / 2) << std::endl;
    return 0;
}