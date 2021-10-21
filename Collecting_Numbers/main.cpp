#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n;
    std::cin >> n;
    std::vector<int> array;
    array.resize(n);
    std::vector<int> vis(n + 1, 0);
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
        vis[array[i]] = i;
    }

    int cnt = 1;
    int pos = -1;
    for (int i = 1; i <= n; i++) {
        if (vis[i] > pos) {
            pos = vis[i];
        } else {
            cnt++;
            pos = vis[i];
        }
    }
    std::cout << cnt << std::endl;
    return 0;
}
