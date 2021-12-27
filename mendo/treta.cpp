#include <iostream>
 
using namespace std;
 
 
int main() {
    int n, l;
    cin >> n >> l;
    int br = 0;
    int lev = 0, des = l;
    for (int i = 0; i < n; i++) {
        //cout << lev << " " << des << endl;
        int a, b;
        cin >> a >> b;
        int sre = (b - a)/2;
        if ((b - a) % 2 == 1) sre++;
        if (a >=lev && b <= des)
            br++;
        else if (a < lev && b <= des && b >= lev && b - lev >= sre)
            br++, lev = min(lev, a);
        else if (b > des && a >= lev && a <= des && des - a >= sre)
            br++, des = max(des, b);
        else
            continue;
        //cout << br << endl;
    }
    cout << br << endl;
    return 0;
}