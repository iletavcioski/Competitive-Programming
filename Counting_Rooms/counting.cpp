#include <bits/stdc++.h>

bool visited[1001][1001];

int n, m;

void floodfill(int x, int y) {
    visited[x][y] = true;
    if (x + 1 < n && !visited[x + 1][y])
        floodfill(x + 1, y);
    if (x - 1 >= 0 && !visited[x - 1][y])
        floodfill(x - 1, y);
    if (y + 1 < m && !visited[x][y + 1])
        floodfill(x, y + 1);
    if (y - 1 >= 0 && !visited[x][y - 1])
        floodfill(x, y - 1);
}
int main() {
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char a;
            std::cin >> a;
            if (a == '#') {
                visited[i][j] = true;
            }
        }
    }

    int counter = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                floodfill(i, j);
                counter++;
            }
        }
    }
    std::cout << counter << std::endl;
    return 0;
}