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
    
    std::string a;
    fin >> a;
    std::vector<int> curr;
    std::vector<int> freespaces;
    int id = 0;
    for (int i = 0; i < a.size(); i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < (a[i] - '0'); j++) {
                curr.push_back(id);
            }
            id++;
        } else {
            for (int j = 0; j < (a[i] - '0'); j++) {
                curr.push_back(-1);
                freespaces.push_back((int)curr.size() - 1);
            }
        }
    }
    int k = curr.size() - 1;
    int idk = 0;
    while (k >= 0 && idk < freespaces.size()) {
        if (curr[k] == -1) {
            k--;
            continue;
        }
        if (freespaces[idk] > k) {
            break;
        }
        curr[freespaces[idk]] = curr[k];
        curr[k] = -1;
        k--;
        idk++;
        
    }
    long long cnt = 0;
    for (int i = 0; i < curr.size(); i++) {
        
        if (curr[i] != -1) {
            cnt += (long long)(curr[i] * i);
        }
    }
    
    std::cout << cnt << std::endl;
    return 0;
}