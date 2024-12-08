#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

bool vis[100][100];
int main() {
    std::ifstream fin("./input.txt");
    
    std::vector<std::string> mapa;
    int n = 50;
    int res = 0;
    int m;
    for (int i = 0; i < n; i++) {
        std::string a;
        fin >> a;
        m = a.size();
        mapa.push_back(a);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int ii = 0; ii < n; ii++) {
                for (int jj = 0; jj < m; jj++) {
                    if (i > ii || (i == ii && j >= jj)) {
                        continue;
                    }
                    if (mapa[i][j] == mapa[ii][jj] && mapa[i][j] != '.') {
                        
                        std::cout << i << " " << j << " " << ii << " " << jj << std::endl;
                        int diffi = ii - i;
                        int diffj = jj - j;
                        std::cout << diffi << " " << diffj << std::endl;
                        int ni = i;
                        int nj = j;
                        if (!vis[ni][nj]) {
                            vis[ni][nj] = true;
                            res++;
                        }
                        while (ni - diffi >= 0 && nj - diffj >= 0 && ni - diffi < n && nj - diffj < m) {
                            if (!vis[ni - diffi][nj - diffj]) {
                                vis[ni - diffi][nj - diffj] = true;
                                res++;
                            }
                            ni -= diffi;
                            nj -= diffj;
                        }
                        ni = ii;
                        nj = jj;
                        if (!vis[ni][nj]) {
                            vis[ni][nj] = true;
                            res++;
                        }
                        while (ni + diffi >= 0 && nj + diffj >= 0 && ni + diffi < n && nj + diffj < m) {
                            if (!vis[ni + diffi][nj + diffj]) {
                                vis[ni + diffi][nj + diffj] = true;
                                res++;
                            }
                            ni += diffi;
                            nj += diffj;
                        }
                    }

                }
            }
        }
    }

    
    
    std::cout << res << std::endl;
    return 0;
}