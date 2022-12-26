#include <bits/stdc++.h>

typedef long long ll;

int main() {
    std::string s;
    std::cin >> s;

    int x = 0, y = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'x') x++;
        if (s[i] == 'y') y++;
    }
    if (x > y) x -= y, y = 0;
    else y -= x, x = 0;

    for (int i = 0; i < x; i++) {
        std::cout << "x";
    }
    for (int i = 0; i < y; i++) {
        std::cout << "y";
    }
    std::cout << "\n";
    return 0;
}