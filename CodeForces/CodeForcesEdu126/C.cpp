#include <bits/stdc++.h>

typedef long long ll;

std::pair<int, int> fun(int x, int y, int start) {
    if (y < x) {
        return {-1, 0};
    }


    int rez = y - x;
    int mrez = rez % 3;
    if (mrez == 0) {
        return {rez / 3, 0};
    }
    if (start == 1) {
        if (mrez == 1) {
            return {(rez / 3) * 2 + 1, 1};
        } 
        if (mrez == 2) {
            return {(rez / 3) * 2 + 2, -1};
        }
    }

    if (start == 2) {
        if (mrez == 1) {
            return {(rez / 3) * 2 + 2, -1};
        } 
        if (mrez == 2) {
            return {(rez / 3) * 2 + 1, 2};
        }
    }

}
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
        v.resize(n);
        for (int i = 0; i < n; i++) {
            std::cin >> v[i];
        }

        int l = 0, r = 1e9;
        int res = 1e9;
        while (l <= r) {
            int mid = (l + r) / 2;
            int kec = 0;
            int dvoj = 0;
            int rez = 0;
            int kecd = 0;
            int dvojd = 0;
            bool cc = true;
            int start = 1;
            for (int i = 0; i < n; i++) {
                std::pair<int, int> p = fun(v[i], mid, start);
                if (p.first == -1) {
                    cc = false;
                    break;
                }
                rez += p.first;

                if (p.second == 1 || p.second == 2) {
                    rez += p.first;
                    kec += p.first / 2;
                    dvoj += p.first / 2;
                    if (start == 1) {
                        kec++;
                    } else if (start == 2) {
                        dvoj++;
                    }
                    start = p.second;
                }  
                if (p.second == 0) {
                    rez += p.first;
                    kec += p.first / 2;
                    dvoj += p.first / 2;
                }
                if (p.second == -1) {
                    rez += p.first;
                    kec += (p.first - 2) / 2;
                    dvoj += (p.first - 2) / 2;
                    if (start == 1) {
                        kec--;
                        kecd++;
                    } else if (start == 2) {
                        dvoj--;
                        dvojd++;
                    }
                }

            }
            rez -= std::min(kecd, kec);
            rez -= std::min(dvojd, dvoj);
            res = std::min(res, rez);
            if ()
        }

    }
    std::cout << "\n";

    return 0;
}