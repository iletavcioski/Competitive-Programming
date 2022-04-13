#include <bits/stdc++.h>

typedef long long ll;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int y = 0, x = 0;
    int prevy = 0, prevx = 0;
    int steps = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        char ch = s[i];
        int px = x;
        int py = y;
        if (ch == 'R') {
            x++;
        } else if (ch == 'L') {
            x--;
        } else if (ch == 'U') {
            y++;
        } else {
            y--;
        }
        steps++;
        if (std::abs(prevy - y) + std::abs(prevx - x) != steps) {
            steps = 0;
            res++;
            x = px;
            y = py;
            prevx = px;
            prevy = py;
            i--;
        }
    }

    std::cout << res + 1 << "\n";

    return 0;
}