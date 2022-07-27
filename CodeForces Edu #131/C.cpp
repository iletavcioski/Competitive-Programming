#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int t;
    std::cin >> t;

    while (t--) {
        int n, m;
        std::cin >> n >> m;

        std::vector<int> v;
        for (int i = 0; i < m; i++) {
            int a;
            std::cin >> a;
            a--;
            v.push_back(a);
        }

        int l = 0;
        int r = 2 * m;

        int res = 2 * m;

        while (l <= r) {
            int mid = (l + r) / 2;

            std::vector<int> workers(n, 0);
            for (int i = 0; i < m; i++) {
                workers[v[i]]++;
            }

            std::sort(workers.begin(), workers.end());

            bool can = true;
            int j = 0;
            for (int i = n - 1; i >= 0; i--) {
                if (workers[i] > mid) {
                    int available = mid - workers[j];
                    int exceeded = workers[i] - mid;
                    while (j < i and exceeded) {
                        if (available / 2 < 1) {
                            j++;
                            continue;
                        }
                        if (exceeded * 2 > available) {
                            exceeded -= (available / 2);
                            workers[j] += ((available / 2) * 2);
                            available = mid - workers[j];
                        } else if (exceeded * 2 <= available) {
                            workers[j] += exceeded * 2;
                            available = mid - workers[j];
                            exceeded = 0;
                        }
                    }
                    if (exceeded) {
                        can = false;
                        break;
                    }
                }
            }

            if (can) {
                r = mid - 1;
                res = std::min(res, mid);
            } else {
                l = mid + 1;
            }
        }
        std::cout << res << std::endl;
    }

    return 0;
}