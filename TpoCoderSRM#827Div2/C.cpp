#include <string>
#include <vector>
#include <iostream>

class CoinFlipping {
    public:
    int dp[13][51];
    std::vector<std::string> v;
    int n, m;
    int rec(int x, int y) {

        
        if (dp[x][y] > -1) {
            return dp[x][y];
        }

        if (x > 0) {
            dp[x][y] = std::max(dp[x][y], rec(x - 1, y));
            int new_ = 0;
            for (int j = 0; j < m; j++) {
                if (v[x - 1][j] == 'H') {
                    new_--;
                    v[x - 1][j] = 'T';
                } else if (v[x - 1][j] == 'T') {
                    new_++;
                    v[x - 1][j] = 'H';
                }
            }
            dp[x][y] = std::max(dp[x][y], rec(x - 1, y));
            for (int j = 0; j < m; j++) {
                if (v[x - 1][j] == 'H') {
                    v[x - 1][j] = 'T';
                } else if (v[x - 1][j] == 'T') {
                    v[x - 1][j] = 'H';
                }
            }
        }

        if (y > 0) {
            dp[x][y] = std::max(dp[x][y], rec(x, y - 1));
            int new_ = 0;
            for (int j = 0; j < n; j++) {
                if (v[j][y - 1] == 'H') {
                    new_--;
                    v[j][y - 1] = 'T';
                } else if (v[j][y - 1] == 'T') {
                    new_++;
                    v[j][y - 1] = 'H';
                }
            }
            dp[x][y] = std::max(dp[x][y], rec(x, y - 1) + new_);
            for (int j = 0; j < n; j++) {
                if (v[j][y - 1] == 'H') {
                    v[j][y - 1] = 'T';
                } else if (v[j][y - 1] == 'T') {
                    v[j][y - 1] = 'H';
                }
            }
        }

        return dp[x][y];
    }

    int mostHeads(std::vector<std::string> layout) {
        n = layout.size();
        m = layout[0].size();

        v = layout;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j] = -1;
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cnt += (layout[i][j] == 'H');
            }
        }
        dp[0][0] = cnt; 

        
        return rec(n, m);
    }
};
int main() {
    CoinFlipping c; 
    std::cout << c.mostHeads({"HT.HT.HT.HT.", ".HT.HT.HT.HT", "T.HT.HT.HT.H"}) << "\n";
}