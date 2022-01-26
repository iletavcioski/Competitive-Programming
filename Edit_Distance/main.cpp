#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;
    string b;
    
    cin >> a;
    //cout << a << endl;
    cin >> b;
    //cout << b << endl;

    int n = a.size();
    int m = b.size();
    
    int dp[n + 1][m + 1];
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = 1e9;
        }
    }
    
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (j > 0 && i > 0) {
                int add = 1;
                if (a[i - 1] == b[j - 1]) {
                    add = 0;
                }
                dp[i][j] = min(dp[i][j], min(dp[i - 1][j - 1] + add, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1)));
            } else if (i > 0 && j == 0) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            } else if (j > 0 && i == 0) {
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
        }
    }
    //cout << "vleze" << endl;
    cout << dp[n][m] << endl;
    return 0;
}