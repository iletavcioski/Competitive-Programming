#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
long long vis[200][200][4];
std::pair<int, std::pair<int, int> > path[200][200][4];
std::vector<std::string> mapa;
int n = 141;
int m;

int main() {
    std::ifstream fin("./input.txt");
    


    long long res = 0;
  
    for (int i = 0; i < n; i++) {
        std::string a;
        fin >> a;
        m = a.size();
        mapa.push_back(a);
    }

    int si = -1, sj = -1, ei = -1, ej = -1;
    int dir = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mapa[i][j] == 'S') {
                si = i;
                sj = j;
            } else if (mapa[i][j] == 'E') {
                ei = i;
                ej = j;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                vis[i][j][k] = 1e18;
                path[i][j][k] = {-1, {-1, -1}};
            }
        }
    }
    std::queue<int> qi;
    std::queue<int> qj;
    std::queue<int> qd;
    std::queue<std::vector<std::pair<int, int> > >qv;
    std::queue<long long> qs;
    std::vector<std::pair<int, int> > vec;
    vec.push_back({si, sj});
    qv.push(vec);
    qi.push(si);
    qj.push(sj);
    qs.push(0);
    qd.push(0);
    int di[] = {0, -1, 0, 1};
    int dj[] = {1, 0, -1, 0};
    vis[0][0][0] = 0;
    std::vector<std::pair<int, int> > resv;
    long long mini = 1e18;
    while (!qi.empty()) {
        int ti = qi.front();
        qi.pop();
        int tj = qj.front();
        qj.pop();
        long long ts = qs.front();
        qs.pop();
        int td = qd.front();
        qd.pop();
        std::vector<std::pair<int, int> > tv = qv.front();
        qv.pop();
       
        if (ti == ei && tj == ej) {
            std::cout << "VLEZE" << " " << ts << std::endl;
            if (ts < mini) {
                resv = tv;
                mini = ts;
            } else if (ts == mini) {
                for (auto x : tv) {
                    resv.push_back(x);
                }
            }
            continue;
        }
        int adi = di[td];
        int adj = dj[td];
        if (ti + adi >= 0 && ti + adi < n && tj + adj >= 0 && tj + adj < m && vis[ti + adi][tj + adj][td] >= ts + 1 && mapa[ti + adi][tj + adj] != '#') {
            vis[ti + adi][tj + adj][td] = ts + 1;
            tv.push_back({ti + adi, tj + adj});
            qv.push(tv);
            tv.pop_back();
            qi.push(ti + adi);
            qj.push(tj + adj);
            qs.push(ts + 1);
            qd.push(td);
        }
        int ntd = (td + 1) % 4;
        if (vis[ti][tj][ntd] >= ts + 1000) {
            vis[ti][tj][ntd] = ts + 1000;
            qv.push(tv);
            qi.push(ti);
            qj.push(tj);
            qs.push(ts + 1000);
            qd.push(ntd);
        }
        ntd = (td - 1 + 4) % 4;
        if (vis[ti][tj][ntd] >= ts + 1000) {
            vis[ti][tj][ntd] = ts + 1000;
            qv.push(tv);
            qi.push(ti);
            qj.push(tj);
            qs.push(ts + 1000);
            qd.push(ntd);
        }
    }
    int result = 0;
    
    for (auto x : resv) {
        mapa[x.first][x.second] = 'O';
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mapa[i][j] == 'O') {
                result++;
            }
        }
    }
    std::cout << result << std::endl;
    return 0;
}