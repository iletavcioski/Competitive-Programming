#include <iostream>

int main() {
    long long n;
    std::cin >> n;
    long long res = 550;
    
    
    
    for (long long i = 1; i <= n; i++) {
        if (i == 1) {
            std::cout << 0 << std::endl;
        } else if (i == 2) {
            std::cout << 6 << std::endl;
        } else if (i == 3) {
            std::cout << 28 << std::endl;
        } else if (i == 4) {
            std::cout << 96 << std::endl;
        } else if (i == 5) {
            std::cout << 252 << std::endl;
        } else if (i == 6) {
            std::cout << 550 << std::endl;
        } else {
            long long cnt = 0;
            long long last = i + i - 1;
            //std::cout << "--------" << std::endl;
            //std::cout << res << std::endl;
            res += (((last * (last - 1)) - 4) / 2);
            
            
            //std::cout << res << std::endl;
            cnt = 0;
            
            cnt += 3 * ((i - 1) * (i - 1) - 2);
            res += cnt;
            //std::cout << res << std::endl;
            last -= 9;
            res += last * ((i - 1) * (i - 1) - 4);
            //std::cout << res << std::endl;
            res += 2 * ((i - 1) * (i - 1) - 3);
            //std::cout << res << std::endl;
            res += 2 * ((i - 1) * (i - 1) - 3);
            //std::cout << res << std::endl;
            res += 2 * ((i - 1) * (i - 1) - 2);
            //std::cout << res << std::endl;
            std::cout << res << std::endl;
        }

    }
    return 0;
}