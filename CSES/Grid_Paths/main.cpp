#include <iostream>

std::string s;

bool vis[7][7];
int res = 0;
void rec(int x, int y, int num_vis, char dir) {

    //std::cout << x << " " << y << " " << num_vis << " " << dir << "\n";
    if (x == 6 && y == 0 && num_vis == 49) {
        res++;
        return;
    }

    if (x == 6 && y == 0 && num_vis < 49) {
        return;
    }

    if (dir == 'L') {
        if (y - 1 < 0 || vis[x][y - 1]) {
            if ((x + 1 <= 6 && !vis[x + 1][y]) && (x - 1 >= 0 && !vis[x - 1][y])) {
                return;
            }
        }
    }

    if (dir == 'R') {
        if (y + 1 >= 7 || vis[x][y + 1]) {
            if ((x + 1 <= 6 && !vis[x + 1][y]) && (x - 1 >= 0 && !vis[x - 1][y])) {
                return;
            }
        }
    }

    if (dir == 'U') {
        if (x - 1 < 0 || vis[x - 1][y]) {
            if ((y + 1 <= 6 && !vis[x][y + 1]) && (y - 1 >= 0 && !vis[x][y - 1])) {
                return;
            }
        }
    }

    if (dir == 'D') {
        if (x + 1 >= 7 || vis[x + 1][y]) {
            if ((y + 1 <= 6 && !vis[x][y + 1]) && (y - 1 >= 0 && !vis[x][y - 1])) {
                return;
            }
        }
    }

    if ((s[num_vis - 1] == '?' || s[num_vis - 1] == 'U') && x - 1 >= 0 && !vis[x - 1][y]) {
        vis[x - 1][y] = true;
        rec(x - 1, y, num_vis + 1, 'U');
        vis[x - 1][y] = false;
    }

    if ((s[num_vis - 1] == '?' || s[num_vis - 1] == 'D') && x + 1 <= 6 && !vis[x + 1][y]) {
        vis[x + 1][y] = true;
        rec(x + 1, y, num_vis + 1, 'D');
        vis[x + 1][y] = false;
    }

    if ((s[num_vis - 1] == '?' || s[num_vis - 1] == 'L') && y - 1 >= 0 && !vis[x][y - 1]) {
        vis[x][y - 1] = true;
        rec(x, y - 1, num_vis + 1, 'L');
        vis[x][y - 1] = false;
    }

    if ((s[num_vis - 1] == '?' || s[num_vis - 1] == 'R') && y + 1 <= 6 && !vis[x][y + 1]) {
        vis[x][y + 1] = true;
        rec(x, y + 1, num_vis + 1, 'R');
        vis[x][y + 1] = false;
    }
    return;
}

int main() {
    std::cin >> s;
    vis[0][0] = 1;
    rec(0, 0, 1, '-');

    std::cout << res << "\n";
    return 0;
}