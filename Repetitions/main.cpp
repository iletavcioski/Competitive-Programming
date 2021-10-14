#include <iostream>
#include <string>

std::string str;

void read() {
    std::cin >> str;
}

void solve(std::string &s) {
    int max = 0;
    char last = '0';
    int cnt = 0;
    for (char a : s) {
        if (a != last) {
            max = std::max(max, cnt);
            last = a;
            cnt = 1;
        } else {
            cnt++;
        }
    }
    max = std::max(max, cnt);
    std::cout << max << std::endl;
}

int main() {
    read();
    solve(str);
    return 0;
}
