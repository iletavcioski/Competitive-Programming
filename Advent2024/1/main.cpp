#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
    std::ifstream fin("./input.txt");
    
    std::vector<long long> v1;
    std::vector<long long> v2;
    std::map<long long, int> mapa;

    for (int i = 0; i < 1000; i++) {
        int a, b;
        fin >> a >> b;
        v1.push_back(a);
        v2.push_back(b);
        mapa[b]++;
    }

    long long res = 0;
    for (int i = 0; i < 1000; i++) {
        res += (v1[i] * (long long)mapa[v1[i]]);
    }
    std::cout << res << std::endl;
    return 0;
}