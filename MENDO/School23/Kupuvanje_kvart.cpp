#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <iostream>

int middle;
std::set<int> lower, upper;

void add(int x) {
    if (x > middle) {
        lower.insert(middle);
        upper.insert(x);
        middle = *upper.begin();
        upper.erase(middle);
    } else {
        upper.insert(middle);
        lower.insert(x);
        middle = *lower.rbegin();
        lower.erase(middle);
    }
}

void del(int x) {
    if (x < middle) {
        lower.erase(x);
        lower.insert(middle);
        middle = *upper.begin();
        upper.erase(middle);
    } else if (x > middle){
        upper.erase(x);
        upper.insert(middle);
        middle = *lower.rbegin();
        lower.erase(middle);
    } else {
        middle = *upper.begin();
        upper.erase(middle);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    // std::ifstream fin("./input/979ET_12.IN");
    int n, k;
    std::cin >> n >> k;

    int mat[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> mat[i][j];
        }
    }

    if (k == 1) {
        int res = mat[0][0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res = std::min(mat[i][j], res);
            }
        }
        std::cout << res << std::endl;
        return 0;
    }
    std::vector<int> v;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            v.push_back(mat[i][j]);
        }
    }
    std::sort(v.begin(), v.end());

    for (int i = 0; i < v.size() / 2; i++) {
        lower.insert(v[i]);
    }
    middle = v[(int)v.size() / 2];
    for (int i = (int)v.size() / 2 + 1; i < v.size(); i++) {
        upper.insert(v[i]);
    }
    int min = middle;
    int i = 0, j = 0;
    int dir = 1;
    while (i + k + 1 <= n) {
        if (dir == 1) {
            if (j + k + 1 <= n) {
                j++;
                for (int ii = i; ii < i + k; ii++) {
                    del(mat[ii][j - 1]);
                }
                for (int ii = i; ii < i + k; ii++) {
                    add(mat[ii][j + k - 1]);
                }

            } else {
                dir = -1;
                i++;
                for (int jj = j; jj < j + k; jj++) {
                    del(mat[i - 1][jj]);
                }
                for (int jj = j; jj < j + k; jj++) {
                    add(mat[i + k - 1][jj]);
                }
            }

        } else {
            if (j > 0) {
                j--;
                for (int ii = i; ii < i + k; ii++) {
                    del(mat[ii][j + k]);
                }
                for (int ii = i; ii < i + k; ii++) {
                    add(mat[ii][j]);
                }
            } else {
                dir = 1;
                i++;
                for (int jj = j; jj < j + k; jj++) {
                    del(mat[i - 1][jj]);
                }
                for (int jj = j; jj < j + k; jj++) {
                    add(mat[i + k - 1][jj]);
                }
            }
        }

        
        while (upper.size() > lower.size()) {
            lower.insert(middle);
            middle = *upper.begin();
            upper.erase(middle);
        }

        while (lower.size() > upper.size()) {
            upper.insert(middle);
            middle = *lower.rbegin();
            lower.erase(middle);
        }
        
        min = std::min(middle, min);
    }
    std::cout << min << std::endl;
    return 0;
}