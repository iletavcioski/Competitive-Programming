#include <iostream>
#include <vector>
#include <queue>
#include <map>
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();
 
    int boys, girls, m;
    std::cin >> boys >> girls >> m;
    int n = boys + girls;
    int start = 0;
    int end = n + 1;
 
    int mat[1002][1002];
 
    std::vector<std::pair<int, int> > edges;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            mat[i][j] = 0;
        }
    }
 
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        edges.push_back({a, b + boys});        
        mat[a][b + boys] = 1;
    }
    for (int i = 1; i <= boys; i++) {
        mat[0][i] = 1;
    }
 
    for (int i = 1; i <= girls; i++) {
        mat[boys + i][end] = 1;
    }
 
 
    long long res = 0;
 
    bool there_is_path = true;
 
    while(there_is_path) {
        std::queue<int> qi;
        qi.push(start);
        std::queue<long long> qs;
        qs.push(0);
 
        std::vector<long long> distances(n + 2, 1e18);
        std::vector<int> parent(n + 2, -1);
        std::vector<bool> vis(n + 2, false);
        vis[0] = true;
        distances[0] = 0;
        while (!qi.empty()) {
            int topi = qi.front();
            qi.pop();
            int tops = qs.front();
            qs.pop();
            //std::cout << topi << " " << tops << "\n";
            for (int i = 0; i <= end; i++) {
                if (mat[topi][i] != 0 and !vis[i]) {
                    distances[i] = tops + mat[topi][i];
                    qs.push(tops + mat[topi][i]);
                    qi.push(i);
                    parent[i] = topi;
                    vis[i] = true;
                }
            }
        }
        if (distances[end] == 1e18) {
            break;
        }
 
        int y = end;
        int min = 1e9;
        while (parent[y] != -1) {
            if (min > mat[parent[y]][y]) {
                min = mat[parent[y]][y];
            }
            y = parent[y];
        }
        y = end;
        while (parent[y] != -1) {
            mat[parent[y]][y] -= min;
            mat[y][parent[y]] += min;
            y = parent[y];
        }
        res += min;
    }
 
    std::queue<int> qi;
    qi.push(start);
    std::queue<long long> qs;
    qs.push(0);
 
    std::vector<long long> distances(n + 2, 1e18);
    std::vector<int> parent(n + 2, -1);
    std::vector<bool> vis(n + 2, false);
    vis[0] = true;
    distances[0] = 0;
    while (!qi.empty()) {
        int topi = qi.front();
        qi.pop();
        int tops = qs.front();
        qs.pop();
        // std::cout << topi << " " << tops << "\n";
        for (int i = 0; i <= end; i++) {
            if (mat[topi][i] != 0 and !vis[i]) {
                distances[i] = tops + mat[topi][i];
                qs.push(tops + mat[topi][i]);
                qi.push(i);
                parent[i] = topi;
                vis[i] = true;
            }
        }
    }
 
    
    std::cout << res << "\n";
    for (auto p : edges) {
        if (mat[p.first][p.second] == 0)
            std::cout << p.first << " " << p.second - boys << "\n";
        
    }
    return 0;
}