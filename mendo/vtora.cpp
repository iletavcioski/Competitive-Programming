#include <iostream>
 
using namespace std;
 
 
int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int pre = n- ((n/a)*a);
    if (((n/a) < (pre + ((n/a)*b))/c)) cout << "DA";
    else cout << "NE";
    cout << endl;
    return 0;
}