#include <bits/stdc++.h>

typedef long long ll;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie();
    std::cin.tie();

    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;

        std::string cur = "";
        bool start = true;
        bool only_pal = false;
        char startch = '-';
        int last = -1;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (start) {
                start = false;
                if (s[i] == ')') {
                    only_pal = true;
                }
                startch = s[i];
            } else {
                if (only_pal) {
                    if (s[i] == startch) {
                        start = true;
                        last = i;
                        startch = '-';
                        cnt++;
                        only_pal = false;
                    }
                } else {
                    cnt++;
                    start = true;
                    last = i;
                    startch = '-';
                    only_pal = false;
                }
            }
        }
        std::cout << cnt << " " << (n - 1 - last) << "\n";
    }


    return 0;
}