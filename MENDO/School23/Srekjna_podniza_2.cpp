#include <iostream>
#include <vector>
#include <string>
#include <map>
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();
 
    int n, k;
    std::cin >> n >> k;
 
    std::vector<int> v;
    std::vector<int> vis(k, 0);
 
    v.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }
 
    int maxi = 0;
    int l = 0, r = 0;
    int number_of_three = 0;
    int number_of_less = k;
    int number_of_more = 0;
    while (l < n && r < n) {
        bool cc = true;
        bool povekje = false;
        bool pomalku = false;
        if (number_of_less > 0) {
            pomalku = true;
            cc = false;
        }

        if (number_of_more > 0) {
            povekje = true;
            cc = false;
        }

        if (cc) {
            maxi = std::max(r - l, maxi);
            if (v[r] < k) {
                if (vis[v[r]] == 2) {
                    number_of_less--;
                    number_of_three++;
                } else if (vis[v[r]] == 3) {
                    number_of_three--;
                    number_of_more++;
                }
                vis[v[r]]++;

            }
            r++;
        } else if (povekje) {
            if (v[l] < k) {
                if (vis[v[l]] == 4) {
                    number_of_more--;
                    number_of_three++;
                } else if (vis[v[l]] == 3) {
                    number_of_three--;
                    number_of_less++;
                }
                vis[v[l]]--;
            }
            l++;
        } else {
            if (v[r] < k) {
                if (vis[v[r]] == 2) {
                    number_of_less--;
                    number_of_three++;
                } else if (vis[v[r]] == 3) {
                    number_of_three--;
                    number_of_more++;
                }
                vis[v[r]]++;
            }
            r++;
        }
    }
 
    bool cc = true;
    if (number_of_less > 0 || number_of_more > 0) {
        cc = false;
    }
 
    if (cc) {
        maxi = std::max(maxi, r - l);
    }
    std::cout << maxi << std::endl;
    return 0;
}