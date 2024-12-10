#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

int vis[100][100];
int main() {
    std::ifstream fin("./input.txt");
    
    std::vector<std::string> mapa;
    int n = 53;
    int res = 0;
    int m;
    for (int i = 0; i < n; i++) {
        std::string a;
        fin >> a;
        m = a.size();
        mapa.push_back(a);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mapa[i][j] == '0') {
                cnt++;
                std::queue<int> qi;
                std::queue<int> qj;
                std::queue<int> qs;
                int dx[] = {0, 0, 1, -1};
                int dy[] = {1, -1, 0, 0};
                qi.push(i);
                qj.push(j);
                qs.push(mapa[i][j] - '0');
                vis[i][j] = cnt;
                while (!qi.empty()) {
                    int ti = qi.front();
                    int tj = qj.front();
                    int ts = qs.front();
                    qi.pop();
                    qj.pop();
                    qs.pop();
                    if (mapa[ti][tj] == '9') {
                        res++;
                        continue;
                    }
                    for (int dir = 0; dir < 4; dir++) {
                        int gx = dx[dir];
                        int gy = dy[dir];
                        if (ti + gx < n && ti + gx >= 0 && tj + gy < m && tj + gy >= 0 && (int)(mapa[ti + gx][tj + gy] - '0') == (ts + 1) ) {
                            
                            qi.push(ti + gx);
                            qj.push(tj + gy);
                            qs.push(ts + 1);

                        }
                    }
                }

                

            }
        }
    }
    
    
    std::cout << res << std::endl;
    return 0;
}