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
            per[y + 1][x - 1 + 1][0] = cnt;
            if (y + 1 < n && per[y + 1 + 1][x - 1 + 1][0] == cnt)
                add = false;
            if (y - 1 >= 0 && per[y - 1 + 1][x - 1 + 1][0] == cnt)
                add = false;
            if (add) 
                perimeter++;
        }
        if (x + 1 == m || mapa[y][x + 1] != a) {
            bool add = true;
            per[y + 1][x + 1 + 1][1] = cnt;
            if (y + 1 < n && per[y + 1 + 1][x + 1 + 1][1] == cnt)
                add = false;
            if (y - 1 >= 0 && per[y - 1 + 1][x + 1 + 1][1] == cnt)
                add = false;
            if (add) 
                perimeter++;
        }
        if (y - 1 < 0 || mapa[y - 1][x] != a) {
            bool add = true;
            per[y - 1 + 1][x + 1][2] = cnt;
            if (x + 1 < m && per[y - 1 + 1][x + 1 + 1][2] == cnt)
                add = false;
            if (x - 1 >= 0 && per[y - 1 + 1][x - 1 + 1][2] == cnt)
                add = false;
            if (add) 
                perimeter++;
        }
        if (y + 1 == n || mapa[y + 1][x] != a) {
            bool add = true;
            per[y + 1 + 1][x + 1][3] = cnt;
            if (x + 1 < m && per[y + 1 + 1][x + 1 + 1][3] == cnt)
                add = false;
            if (x - 1 >= 0 && per[y + 1 + 1][x - 1 + 1][3] == cnt)
                add = false;
            if (add) 
                perimeter++;
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
                res += (long long)((long long)perimeter * (long long)plostina);
            }
        }
    }
    
    
    std::cout << res << std::endl;
    return 0;
}