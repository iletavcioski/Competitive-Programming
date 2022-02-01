#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        long long a, b;
        std::cin >> a >> b;
        long long tren = 0;
        if (a >= b) {
            //long long br = (a - 1) * 2 + 1;

            tren = a * a;
            long long dir = a % 2;
            tren -= (a - 1);
            //std::cout << tren << std::endl;
            if (dir == 0) {
                
                tren += a - b;
            } else {

                tren -= a - b;
            }
        } else {
            //long long br = (b - 1) * 2 + 1;
            tren = b * b;
            long long dir = b % 2;
            tren -= (b - 1);
            //std::cout << tren << std::endl;
            if (dir == 1) {
                
                tren += b - a;
            } else {
                
                tren -= b - a;
            }
        }
        std::cout << tren << std::endl;
    }
    return 0;
}