#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

const int mod = 1000000007;
int map[(1 << 10)];
bool vis[(1 << 10)];


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, m;
    std::cin >> n >> m;
 
 
    int dp[(1 << 10)][2];
 
    int first = 0;
    int second = 1;
 
    std::queue<int> q;
    std::queue<int> qj;
    std::vector<int> options;

    for (int i = 0; i < (1 << n); i++) {
        int continuing = 0;
        bool itcant = false;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                if (continuing % 2) {
                    itcant = true;
                    break;
                }
                continuing = 0;
            } else {
                continuing++;
            }
        }
        if (continuing % 2) {
            itcant = true;
        }
        if (!itcant) {
            vis[i] = true;
            options.push_back(i);
            q.push(i);
            qj.push(0);
            dp[i][first] = 1;
        }
    }

    
    for (int j = 1; j < m; j++) {

        while (qj.front() < j) {
            int bitmask = q.front();
            q.pop();
            qj.pop();
 
            int num_zeros = 0;
            int visited = 0;

            for (int i = 0; i < options.size(); i++) {
                int candidate = 0;
                if ((bitmask | options[i]) == options[i]) {
                    candidate = bitmask ^ options[i];
                    if (map[candidate] != j) {
                        q.push(candidate);
                        qj.push(j);
                        map[candidate] = j;
                        dp[candidate][second] = 0;
                    }

                    dp[candidate][second] += dp[bitmask][first];
                    dp[candidate][second] %= mod;
                }
            }
        }

        int t = first;
        first = second;
        second = t;
    }
 
    std::cout << dp[0][first] << std::endl;
    return 0;
}