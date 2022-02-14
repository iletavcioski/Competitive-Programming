#include <iostream>

char forest[1001][1001];
int ft[1001][1001];

void up_2(int x, int y, int val) {
    while (y <= 1000) {
        ft[x][y] += val;
        y += (-y & y);
    }
}

void up_1(int x, int y, int val) {
    while (x <= 1000) {
        up_2(x, y, val);
        x += (-x & x);
    }
}



int qu_2(int x, int y) {
    int res = 0;
    while (y) {
        res += ft[x][y];
        y -= (-y & y);
    }
    return res;
}

int qu_1(int x, int y) {
    int res = 0;
    while (x) {
        res += qu_2(x, y);
        x -= (-x & x);
    }
    return res;
}



int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, m;
    std::cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cin >> forest[i][j];
            if (forest[i][j] == '*') {
                up_1(i, j, 1);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int a;
        std::cin >> a;
        if (a == 1) {
            int x, y;
            std::cin >> x >> y;
            if (forest[x][y] == '*') {
                forest[x][y] = '.';
                up_1(x, y, -1);
            } else {
                forest[x][y] = '*';
                up_1(x, y, 1);
            }
        } else {
            int x1, y1, x2, y2;
            std::cin >> x1 >> y1 >> x2 >> y2;
            std::cout << qu_1(x2, y2) - qu_1(x1 - 1, y2) - qu_1(x2, y1 - 1) + qu_1(x1 - 1, y1 - 1) << "\n";
        }
    }

    

}