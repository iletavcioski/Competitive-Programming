#include <iostream>
#include <vector>

int N;
std::vector<int> array;

void read() {
    std::cin >> N;
    array.resize(N - 1);
    for (int i = 0; i < N - 1; i++) {
        std::cin >> array[i];
    }
}

void solve(int &n, std::vector<int> &v) {
    std::vector<int> vis(n + 1, 0);

    for (int i : v) {
        vis[i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            std::cout << i << std::endl;
            break;
        }
    }
}

int main() {
    read();
    solve(N, array);
    return 0;
}
