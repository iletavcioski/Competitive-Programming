#include <bits/stdc++.h>

typedef long long ll;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int vp, vd, t, f, c;
    std::cin >> vp >> vd >> t >> f >> c;
    
    int sol = 0;
    while (true) {
        int t1 = t;
        bool cc = false;
        int sp = 0;
        for (int i = 0; i <= sol; i++) {
            
            sp += vp * t;
            int sd = 0;
            
            int td = ((sp - sd) / (vd - vp));
            
            sp += (td * vp);
            
            if (sp >= c) {
                cc = true;
                break;
            }
            t = td + f;

        }
        t = t1;
        
        if (cc) {
            break;
        }
        sol++;
    }
    std::cout << sol << "\n";
    
    return 0;
}