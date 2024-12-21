#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int vis[200][200];
std::vector<std::string> mapa;
int perimeter = 0;
int plostina = 0;
int cnt = 0;

int n = 50;
int m;

int main() {
    std::ifstream fin("./input.txt");
    


    long long res = 0;
    int si = 0;
    int sj = 0;
    for (int i = 0; i < n; i++) {
        std::string a;
        fin >> a;
        m = a.size();
        mapa.push_back(a);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mapa[i][j] == '@') {
                si = i;
                sj = j;
                break;
            }
        }
    }
    std::string moves = "";
    for (int i = 0; i < 21; i++) {
        std::string a;
        fin >> a;
        moves += a;
    }
    
    for (int i = 0; i < moves.size(); i++) {
        char move = moves[i];
        if (move == '^') {
            int ei = si;
            while (mapa[ei][sj] != '.') {
                ei--;
                if (ei < 0) {
                    break;
                }
                if (mapa[ei][sj] == '#') {
                    break;
                }
            }
            if (ei >= 0 && mapa[ei][sj] == '.') {
                for (int ii = ei + 1; ii <= si; ii++) {
                    mapa[ii - 1][sj] = mapa[ii][sj];
                    mapa[ii][sj] = '.';
                }
                si--;
            }
        }
        if (move == 'v') {
            int ei = si;
            while (mapa[ei][sj] != '.') {
                ei++;
                if (ei == n) {
                    break;
                }
                if (mapa[ei][sj] == '#') {
                    break;
                }
            }
            if (ei < n && mapa[ei][sj] == '.') {
                for (int ii = ei - 1; ii >= si; ii--) {
                    mapa[ii + 1][sj] = mapa[ii][sj];
                    mapa[ii][sj] = '.';
                }
                si++;
            }
        }
        if (move == '<') {
            int ej = sj;
            while (mapa[si][ej] != '.') {
                ej--;
                if (ej < 0) {
                    break;
                }
                if (mapa[si][ej] == '#') {
                    break;
                }
            }
            if (ej >= 0 && mapa[si][ej] == '.') {
                for (int jj = ej + 1; jj <= sj; jj++) {
                    mapa[si][jj - 1] = mapa[si][jj];
                    mapa[si][jj] = '.';
                }
                sj--;
            }
        }
        if (move == '>') {
            int ej = sj;
            while (mapa[si][ej] != '.') {
                ej++;
                if (ej == m) {
                    break;
                }
                if (mapa[si][ej] == '#') {
                    break;
                }
            }
            if (ej >= 0 && mapa[si][ej] == '.') {
                for (int jj = ej - 1; jj >= sj; jj--) {
                    mapa[si][jj + 1] = mapa[si][jj];
                    mapa[si][jj] = '.';
                }
                sj++;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mapa[i][j] == 'O') {
                res += (100 * i + j);
            }
        }
    }
    std::cout << res << std::endl;
    return 0;
}