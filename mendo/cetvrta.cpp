#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int n, l;
    cin >> n >> l;
    int br = 0;
    int lev = 0, des = l;
    vector<bool> vis(n, false);
    int iter = 5000;
    vector<int> a, b;
    for (int i = 0; i < n; i++)  {
        int aa, bb;
        cin >> aa >> bb;
        a.push_back(aa);
        b.push_back(bb);
    }
    while (iter--) {
        for (int i = 0; i < n; i++) {
            //cout << lev << " " << des << endl;
            if (vis[i]) continue;
            int sre = (b[i] - a[i]) / 2;
            if ((b[i] - a[i]) % 2 == 1) sre++;
            if (a[i] >= lev && b[i] <= des)
                br++,vis[i] = true;
            else if (a[i] < lev && b[i] <= des && b[i] >= lev && b[i] - lev >= sre)
                br++, vis[i] = true, lev = min(lev, a[i]);
            else if (b[i] > des && a[i] >= lev && a[i] <= des && des - a[i] >= sre)
                br++, vis[i] = true, des = max(des, b[i]);
            else
                continue;
            //cout << br << endl;
        }
    }
    cout << br << endl;
    return 0;
}