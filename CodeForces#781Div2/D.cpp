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
        ll result = 0;
 
        for (ll i = 0; i < 30; i++) {
            ll a = (1 << i) - result;
            ll b = a + (1 << (i + 1));
            std::cout << "? " << a << " " << b << std::endl;
            ll res = 0;
            std::cin >> res;
            if (res == (1 << (i + 1))) {
                
                result += (1 << (i));
            }
        }
        std::cout << "! " << result << std::endl;
        
        
    }
    return 0;
}