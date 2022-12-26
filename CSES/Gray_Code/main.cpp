#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

std::vector<int> v;


std::string int2bit(int n, int x) {
    std::string s = "";
    while (x > 0) {
        s += ((x % 2) + '0');
        x /= 2;
    }
    while (s.size() < n) {
        s += '0';
    }
    std::reverse(s.begin(), s.end());
    return s;
}

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < (1 << n); i++) {
        v.push_back(i);
    }

    for (int i = 1; i < n; i++) {
        int len = (1 << i);
        for (int j = len; j < (1 << n); j += 2*len) {
            std::reverse(v.begin() + j, v.begin() + j + len);
        }
        //std::cout << "<------------------>" << "\n";
        //for (int j = 0; j < v.size(); j++) {
            //std::cout << int2bit(n, v[j]) << "\n";
        //}
    }

    for (int j = 0; j < v.size(); j++) {
        std::cout << int2bit(n, v[j]) << "\n";
    }
    return 0;
}