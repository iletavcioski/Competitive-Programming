#include <iostream>

char board[8][8];
int vis[8][8];
int right[8][8];
int left[8][8];
int nright[8][8];
int nleft[8][8];
int nvis[8][8];

int res = 0;

void rec(int pos, int k) {
    //std::cout << "<--------------->\n";
    if (k == 0) {
        res++;
        return;
    }


    if (8 - k > 0) {
        for (int i = 7; i >= 1; i--) {
            right[8 - k][i] = right[8 - k - 1][i - 1];
        }
        right[8 - k][0] = 0;

        for (int i = 0; i < 7; i++) {
            left[8 - k][i] = left[8 - k - 1][i + 1];
        }
        left[8 - k][7] = 0;

        for (int i = 0; i < 8; i++) {
            vis[8 - k][i] = vis[8 - k - 1][i];
        }
    }


    /*
    std::cout << "right\n";
    for (int i = 0; i < 8; i++) {
        std::cout << right[8 - k][i] << ' ';
    }
    std::cout << '\n';
    std::cout << "left\n";
    for (int i = 0; i < 8; i++) {
        std::cout << left[8 - k][i] << ' ';
    }
    std::cout << '\n';
    std::cout << "vis\n";
    for (int i = 0; i < 8; i++) {
        std::cout << vis[8 - k][i] << ' ';
    }
    std::cout << '\n';
    */
    for (int i = 0; i < 8; i++) {
        if (!vis[8 - k][i] && !right[8 - k][i] && !left[8 - k][i] && board[8 - k][i] == '.') {
            for (int j = 0; j < 8; j++) {
                nright[8 - k][j] = right[8 - k][j];
                nleft[8 - k][j] = left[8 - k][j];
                nvis[8 - k][j] = vis[8 - k][j];
            }
            vis[8 - k][i] = 1;
            right[8 - k][i] = 1;
            left[8 - k][i] = 1;
            rec(i, k - 1);
            for (int j = 0; j < 8; j++) {
                right[8 - k][j] = nright[8 - k][j];
                left[8 - k][j] = nleft[8 - k][j];
                vis[8 - k][j] = nvis[8 - k][j];
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::cin >> board[i][j];
        }
    }

    rec(-1, 8);
    std::cout << res << '\n';


    return 0;
}
