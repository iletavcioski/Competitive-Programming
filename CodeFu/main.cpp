#include <string>
#include <vector>
#include <queue>
#include <algorithm>
//#include <iostream>
using namespace std;

class DungeonScramble
{
  public:
    char mat[33][33];
    int dist[10][10];
    int bfs(int si, int sj, int ei, int ej, int n, int m) {
        int dx[] = {0, -1, 0, 1};
        int dy[] = {-1, 0, 1, 0};
        bool visited[33][33];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                visited[i][j] = false;
                if (mat[i][j] == '#') {
                    visited[i][j] = true;
                }
            }
        }
        queue<int> qi;
        queue<int> qj;
        queue<int> qs;
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
                return result;
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
                    }
                }
            }
        }
        return 1e9;
    }
    int collectArtifacts(vector<string> dungeonMap)
    {
        int n = dungeonMap.size();
        int m = dungeonMap[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[i][j] = dungeonMap[i][j]; 
            }
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                dist[i][j] = 1e9;
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((mat[i][j] >= '1' && mat[i][j] <= '9')) cnt++;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((mat[i][j] >= '1' && mat[i][j] <= '9') || mat[i][j] == 'S') {
                    int s = 0;
                    if (mat[i][j] == 'S') {
                        s = 0;
                    } else {
                        s = mat[i][j] - '0';
                    }

                    for (int ii = 0; ii < n; ii++) {
                        for (int jj = 0; jj < m; jj++) {
                            if ((mat[ii][jj] >= '1' && mat[ii][jj] <= '9') || mat[ii][jj] == 'S') {
                                int e = 0;
                                if (mat[ii][jj] == 'S') {
                                    e = 0;
                                } else {
                                    e = mat[ii][jj] - '0';
                                }
                                if (e == 0) {
                                    continue;
                                }

                                dist[s][e] = bfs(i, j, ii, jj, n, m);
                            }
                        }
                    }
                }
            }
        }

        int start = 1;
        for (int i = 1; i < cnt; i++) {
            start *= 10;
        }
        vector<bool> v(10000001,1);
        v[0]=0;
        v[1]=0;
        for(int i=2;i<=10000000;i++)
        {
            if(v[i])
            {
                int p=i;
                for(int j=i+p;j<=10000000;j+=p)
                    v[j]=false;
            }
        }
        int maxi = 1e9;
        /*
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                cout << dist[i][j] << " ";
            }
            cout << endl;
        }
        */

        for (int i = start; i <= 10000000; i++) {

            if (v[i]) {
                vector<int> vis(10);
                bool ok = true;
                string s =  "";
                int p = i;
                while (p > 0) {
                    s+= ((p%10) + '0');
                    vis[p%10] += 1;
                    if (p % 10 == 0) {
                        ok = false;
                        break;
                    }
                    if (vis[p%10] == 2) {
                        ok = false;
                        break;
                    }
                    p/=10;
                }
                if (ok == false) {
                    continue;
                }
                s += '0';
                reverse(s.begin(), s.end());
                int sol = 0;

                for (int j = 0; j < s.size() - 1; j++) {
                    if (dist[s[j] - '0'][s[j + 1] - '0'] < 100000000) {
                        sol += dist[s[j] - '0'][s[j + 1] - '0'];
                    } else {
                        sol = 1e9;
                    }
                }
                if (sol != 0) {
                    if (sol < maxi) {
                        maxi = sol;
                        //cout << i << endl;
                    }
                    
                }
            }
        }


      return maxi;
  }
};
/*
int main() {
    DungeonScramble x;
    cout << x.collectArtifacts({"#####","#...#","#9..#","#17S#","#####"}) << endl;
}
*/