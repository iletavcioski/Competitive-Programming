
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
 
typedef long long ll;
 
 
 
using namespace std;
int main() {
 
 
    int t;
    std::cin >> t;
    
 
    while (t--) {
        int result = 0;
 
        for (int i = 1; i <= 30; i++) {
            int a = (1 << i) - result;
            int b = (1 << i);
            cout << "? " << a << " " << b;
            cout << endl;
            int res;
            cin >> res;
            if (res != (1 << i)) {
                if (res == (1 << (i - 1))) {
                    result += (1 << (i - 1));
                }
            }
        }
        cout << "! " << result;
        cout << endl;
        
        
    }
    return 0;
}