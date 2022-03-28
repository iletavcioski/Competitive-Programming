#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>

typedef long long ll;

const ll mod = 998244353;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int t;
    std::cin >> t;
    

    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> v;
        for (int i = 0; i < n; i++) {
            int num;
            std::cin >> num;
            v.push_back(num);
        }

        bool zgolemi2 = false;
        int ones = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == 1) {
                ones++;
            }
            if (i + 1 < n && v[i + 1] - v[i] >= 2) {
                zgolemi2 = true;
                break;
            } else if (i + 1 == n && v[0] - v[i] >= 2) {
                zgolemi2 = true;
                break;
            }
        }
        bool one = ones != 1;

        bool maxna1 = false;
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && v[i + 1] > n - v[i] + 1) {
                maxna1 = true;
                break;
            } else if (i + 1 == n && v[0] > n - v[i] + 1) {
                maxna1 = true;
                break;
            }
        }

        if (zgolemi2 || one) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
        }
    }
    return 0;
}
