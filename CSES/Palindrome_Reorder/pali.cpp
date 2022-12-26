#include <bits/stdc++.h>

int main() {
    std::string st;
    std::cin >> st;

    std::map<char, int> map;
    for (int i = 0; i < st.size(); i++) {
        map[st[i]]++;
    }

    int cnt = 0;
    char odd = '-';
    for (char i = 'A'; i <= 'Z'; i++) {
        if (map[i] % 2) {
            cnt++;
            odd = i;
        }
    }

    if (cnt > 1) {
        std::cout << "NO SOLUTION" << std::endl;
    } else {
        std::string res = "";
        for (char i = 'A'; i <= 'Z'; i++) {
            if (i != odd) {
                for (int j = 0; j < map[i] / 2; j++) {
                    res += i;
                }
            }
        }

        for (int j = 0; j < map[odd]; j++) {
            res += odd;
        }

        for (char i = 'Z'; i >= 'A'; i--) {
            if (i != odd) {
                for (int j = 0; j < map[i] / 2; j++) {
                    res += i;
                }
            }
        }
        std::cout << res << std::endl;
    }
    return 0;
}