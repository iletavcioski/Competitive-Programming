#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int trye[131][200][4];
bool visi[131][200];
int main() {
    std::ifstream fin("./input.txt");
    
    std::vector<std::string> mapa;
    int n = 130;
    int m;
    for (int i = 0; i < n; i++) {
        std::string a;
        fin >> a;
        m = a.size();
        mapa.push_back(a);
    }

    int _si = -1, _sj = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mapa[i][j] == '^') {
                _si = i;
                _sj = j;
                break;
            }
        }
    }
    int tycnt = 0;
    int si = _si;
    int sj = _sj;
    int dir = 0;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {-1, 0, 1, 0};
    int res = 0;
    while (si >= 0 && si < n && sj >= 0 && sj < m) {
        visi[si][sj] = true;
        if (si + dy[dir] >= 0 && si + dy[dir] < n && sj + dx[dir] >= 0 && sj + dx[dir] < m) {
            if (mapa[si + dy[dir]][sj + dx[dir]] == '#') {
                dir++;
                dir %= 4;
            } else {
                si += dy[dir];
                sj += dx[dir];
            }
        } else {
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visi[i][j] != true) {
                continue;
            }
            if (mapa[i][j] == '#' || mapa[i][j] == '^') {
                continue;
            }
            mapa[i][j] = '#';
            
            dir = 0;
            si = _si;
            sj = _sj;
            tycnt++;
            while (si >= 0 && si < n && sj >= 0 && sj < m) {
                
                if (trye[si][sj][dir] != tycnt) 
                    trye[si][sj][dir] = tycnt;
                else {
                    res++;
                    break;
                }
                if (si + dy[dir] >= 0 && si + dy[dir] < n && sj + dx[dir] >= 0 && sj + dx[dir] < m) {
                    if (mapa[si + dy[dir]][sj + dx[dir]] == '#') {
                        dir++;
                        dir %= 4;
                    } else {
                        si += dy[dir];
                        sj += dx[dir];
                    }
                } else {
                    break;
                }
            }
            mapa[i][j] = '.';
        }
    }
    
    std::cout << res << std::endl;
    return 0;
}