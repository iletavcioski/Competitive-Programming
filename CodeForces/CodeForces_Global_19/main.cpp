#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> ar;
        ar.resize(n);
        std::deque<std::pair<int, int> > qi;
        for (int i = 0; i < n; i++) {
            std::cin >> ar[i];
            if (ar[i] % 2 && i > 0 && i < n - 1) {
                qi.push_back({ar[i], i});
            }
        }

        long long cnt = 0;
        for (int i = 1; i < n - 1; i++) {
            if (ar[i] % 2 == 0) {
                while (ar[i] > 0 && qi.size() > 0) {
                    if (i > qi.front().second && qi.back().second > i && qi.back().second != qi.front().second) {
                        cnt++;
                        ar[qi.front().second]++;
                        ar[qi.back().second]++;
                        ar[i] -= 2;
                        qi.pop_back();
                        qi.pop_front();
                    } else if (qi.front().second == qi.back().second) {
                        ar[i] -= 2;
                        ar[qi.front().second]++;
                        qi.pop_back();
                        cnt++;
                    } else {
                        break;
                    }
                }
            }
        }

        for (int i = 1; i < n - 1; i++) {
            if (ar[i] % 2 == 1) {
                while (ar[i] > 1 && qi.size() > 0) {
                    if (i > qi.front().second && qi.back().second > i && qi.back().second != qi.front().second) {
                        cnt++;
                        ar[qi.front().second]++;
                        ar[qi.back().second]++;
                        ar[i] -= 2;
                        qi.pop_back();
                        qi.pop_front();
                    } else if (qi.front().second == qi.back().second) {
                        ar[i] -= 2;
                        ar[qi.front().second]++;
                        qi.pop_back();
                        cnt++;
                    } else {
                        break;
                    }
                }
            }
        }

        

        bool dont = false;
        for (int i = 1; i < n - 1; i++) {
            if (ar[i] % 2) {
                dont = true;
                break;
            }
            cnt += (ar[i] / 2);
        }

        if (dont) {
            std::cout << -1 << '\n';
        } else {
            std::cout << cnt << '\n';
        }
    }

    return 0;
}