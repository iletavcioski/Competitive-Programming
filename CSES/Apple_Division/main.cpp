#include <iostream>
#include <vector>
#include <cmath>
#define maxi 1e18

int main() {
    int n;
    std::cin >> n;

    std::vector<int> apples;
    apples.resize(n);

    long long min = maxi;
    for (int i = 0; i < n; i++) {
        std::cin >> apples[i];
    }

    for (int i = 0; i < (1 << n); i++) {
        long long cnta = 0;
        long long cntb = 0;
        for (int j = 0; j < n; j++) {    
            if ((i & (1 << j))) {
                cnta += apples[j];
            } else {
                cntb += apples[j];
            }
        }

        min = std::min(std::abs(cnta - cntb), min);
    }
    std::cout << min << std::endl;
    return 0;
}