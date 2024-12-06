#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
    std::ifstream fin("./input.txt");
    
    std::vector<std::string> mapa;
    int n = 140;
    int m;
    for (int i = 0; i < 140; i++) {
        std::string a;
        fin >> a;
        m = a.size();
        mapa.push_back(a);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mapa[i][j] == 'A') {
                if (i >= 1 && i + 1 < n && j >= 1 && j + 1 < m) {
                    std::string s = "";
                    s += mapa[i - 1][j - 1];
                    s += mapa[i - 1][j + 1];
                    s += mapa[i + 1][j - 1];
                    s += mapa[i + 1][j + 1];
                    if (s == "MMSS" || s == "MSMS" || s == "SSMM" || s == "SMSM") {
                        cnt++;
                    }
                }
            }
        }
    }
    std::cout << cnt << std::endl;
    return 0;
}