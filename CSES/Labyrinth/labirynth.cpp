#include <bits/stdc++.h>

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

int main() {
    int n, m;
    std::cin >> n >> m;
    std::map<int, char> map;
    map[0] = 'L';
    map[1] = 'U';
    map[2] = 'R';
    map[3] = 'D';

    bool visited[1001][1001];
    int path[1001][1001];
    char mat[1001][1001];
    int si = -1, sj = -1, ei = -1, ej = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = 0;
            path[i][j] = -1;
            std::cin >> mat[i][j];
            if (mat[i][j] == 'A') {
                visited[i][j] = 1;
                si = i;
                sj = j;
            } else if (mat[i][j] == 'B') {
                ei = i;
                ej = j;
            } else if (mat[i][j] == '#') {
                visited[i][j] = true;
            }
        }
    }

    std::queue<int> qi;
    std::queue<int> qj;
    std::queue<int> qs;
    qi.push(si);
    qj.push(sj);
    qs.push(0);

    int result = -1;
    while (!qi.empty()) {
        int topi = qi.front();
        qi.pop();
        int topj = qj.front();
        qj.pop();
        int tops = qs.front();
        qs.pop();

        if (topi == ei && topj == ej) {
            result = tops;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int newi = topi + dx[i];
            int newj = topj + dy[i];

            if (newi >= 0 && newi < n && newj >= 0 && newj < m) {
                if (!visited[newi][newj]) {
                    qi.push(newi);
                    qj.push(newj);
                    qs.push(tops + 1);
                    visited[newi][newj] = true;
                    path[newi][newj] = (i + 2) % 4;
                }
            }
        }
    }

    if (result == -1) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
        std::cout << result << std::endl;
        std::string res = "";
        while (path[ei][ej] != -1) {
            int a = ei, b = ej;
            res += map[(path[a][b] + 2) % 4];
            ei += dx[path[a][b]];
            ej += dy[path[a][b]];
            //std::cout << a << " " << b << std::endl;
        }
        reverse(res.begin(), res.end());
        std::cout << res << std::endl;
    }

    return 0;
}