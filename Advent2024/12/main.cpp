#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int vis[200][200];
int per[200][200][4];
std::vector<std::string> mapa;
int perimeter = 0;
int plostina = 0;
int cnt = 0;

int n = 140;
int m;
void dfs(int x, int y, char a) {
    
    if (mapa[y][x] == a) {
        vis[y][x] = cnt;
        plostina++;
        if (x - 1 < 0 || mapa[y][x - 1] != a) {
            bool add = true;
            int yy = y;
            if (per[y + 1][x - 1 + 1][0] == cnt) {
                add = false;
            } else {
                yy = y;
                while (yy < n && mapa[yy][x] == a && (x - 1 < 0 || mapa[yy][x - 1] != a)) {
                    per[yy + 1][x - 1 + 1][0] = cnt;
                    yy++;
                }
                yy = y;
                while (yy >= 0 && mapa[yy][x] == a && (x - 1 < 0 || mapa[yy][x - 1] != a)) {
                    per[yy + 1][x - 1 + 1][0] = cnt;
                    yy--;
                }
            }
            
            if (add) {
                std::cout << y << " " << x << " " << 0 << std::endl;
                perimeter++;
            }
        }
        if (x + 1 == m || mapa[y][x + 1] != a) {
            bool add = true;
            int yy = y;
            if (per[y + 1][x + 1 + 1][1] == cnt) {
                add = false;
            } else {
                yy = y;
                while (yy < n && mapa[yy][x] == a && (x + 1 == m || mapa[yy][x + 1] != a)) {
                    per[yy + 1][x + 1 + 1][1] = cnt;
                    yy++;
                }
                yy = y;
                while (yy >= 0 && mapa[yy][x] == a && (x + 1 == m || mapa[yy][x + 1] != a)) {
                    per[yy + 1][x + 1 + 1][1] = cnt;
                    yy--;
                }
            }
            
            if (add) {
                std::cout << y << " " << x << " " << 1 << std::endl;
                perimeter++;
            }
        }
        if (y - 1 < 0 || mapa[y - 1][x] != a) {
            bool add = true;
            int yy = y;
            if (per[y - 1 + 1][x + 1][2] == cnt) {
                add = false;
            } else {
                int xx = x;
                while (xx < m && mapa[y][xx] == a && (y - 1 < 0 || mapa[y - 1][xx] != a)) {
                    per[y - 1 + 1][xx + 1][2] = cnt;
                    xx++;
                }
                xx = x;
                while (xx >= 0 && mapa[y][xx] == a && (y - 1 < 0 || mapa[y - 1][xx] != a)) {
                    per[y - 1 + 1][xx + 1][2] = cnt;
                    xx--;
                }
            }
            
            if (add) {
                std::cout << y << " " << x << " " << 2 << std::endl;
                perimeter++;
            }
        }
        if (y + 1 == n || mapa[y + 1][x] != a) {
            bool add = true;
            int yy = y;
            if (per[y + 1 + 1][x + 1][3] == cnt) {
                add = false;
            } else {
                int xx = x;
                while (xx < m && mapa[y][xx] == a && (y + 1 == n || mapa[y + 1][xx] != a)) {
                    per[y + 1 + 1][xx + 1][3] = cnt;
                    xx++;
                }
                xx=x;
                while (xx >= 0 && mapa[y][xx] == a && (y + 1 == n || mapa[y + 1][xx] != a)) {
                    per[y + 1 + 1][xx + 1][3] = cnt;
                    xx--;
                }
            }

            if (add) {
                std::cout << y << " " << x << " " << 3 << std::endl;
                perimeter++;
            }
        }
       
    } else {
        return;
    }
    if (x - 1 >= 0 && !vis[y][x - 1]) {
        dfs(x - 1, y, a);
    }
    if (x + 1 < m && !vis[y][x + 1]) {
        dfs(x + 1, y, a);
    }
    if (y - 1 >= 0 && !vis[y - 1][x]) {
        dfs(x, y - 1, a);
    }
    if (y + 1 < n && !vis[y + 1][x]) {
        dfs(x, y + 1, a);
    }
}
int main() {
    std::ifstream fin("./input.txt");
    


    long long res = 0;
  
    for (int i = 0; i < n; i++) {
        std::string a;
        fin >> a;
        m = a.size();
        mapa.push_back(a);
    }

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) {
                
                cnt++;
                perimeter = 0;
                plostina = 0;
                dfs(j, i, mapa[i][j]);
                std::cout << perimeter << " " << plostina << std::endl;
                res += (long long)((long long)perimeter * (long long)plostina);
            }
        }
    }
    
    
    std::cout << res << std::endl;
    return 0;
}