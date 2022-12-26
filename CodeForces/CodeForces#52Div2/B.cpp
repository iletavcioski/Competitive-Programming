#include <bits/stdc++.h>

typedef long long ll;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n;
    std::cin >> n;

    std::vector<int> v;
    v.resize(n);

    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }
    int bj = -1;
    int bi = -1;
    for (int i = 0; i < n; i++) {
        if (i + 1 < n && v[i] - v[i + 1] > 0) {
            bi = i;
            for (int j = i; j < n; j++) {
                bj = j;
                if (j + 1 < n && v[j + 1] > v[j]) {
                    break;
                } 
            }
            //std::cout << bi << " " << bj << "\n";
            int l = i, r = bj;
            while(l <= r) {
                std::swap(v[l], v[r]);
                l++;
                r--;
            }
            break;
        }
    }

    bool cc = true;
    for (int i = 0; i < n; i++) {
        if (v[i] != i + 1) {
            cc = false;
            break;
        }
    }
    if (cc) {
        std::cout << bi + 1 << " " << bj + 1 << "\n";
    } else {
        std::cout << 0 << " " << 0 << "\n";
    }
    return 0;
}