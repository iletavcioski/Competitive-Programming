#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back

typedef long long ll;
const ll mod = 1000000007;

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

        std::vector<int> v1 = v;
        std::sort(v1.begin(), v1.end());

        int fir = -1;
        int last = -1;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] != v1[i]) {
                if (fir == -1) {
                    fir = i;
                }
                last = i;
            } 
        }

        if (last == -1) {
            std::cout << "Yes" << '\n';
        } else {
            int odf = v[fir] % 2;
            int ods = v[last] % 2;
            if (last - fir )
        }
        
        //std::cout << cnt << "--\n";

        
    }
    return 0;
}