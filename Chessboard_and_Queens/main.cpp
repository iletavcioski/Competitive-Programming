#include <iostream>

char board[8][8];
bool visited[8];

void read() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::cin >> board[i][j];
        }
    }
}

void init() {
    for (int i = 0; i < 8; i++) {
        visited[i] = (board[0][i] == '*');
    }
}

int solve(int row, int pos) {
    if (row == 7)
        return 1;

    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        if (!visited[i]) {
            std::vector<int> positions;
            if (i - 1 >= 0)
                visited[i - 1] = true;
            if (i + 1 < 8)
                visited[i + 1] = true;
            visited[i] = true;
            cnt += solve(row + 1, i);
        }
    }

    return cnt;
}

int main() {
    read();
    init();
    std::cout << solve() << std::endl;
    return 0;
}
