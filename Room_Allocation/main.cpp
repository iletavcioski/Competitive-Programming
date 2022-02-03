#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <queue>

bool compare(const std::array<int, 3> a, const std::array<int, 3> b) {
    if (a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();
    
    int n;
    std::cin >> n;

    std::array<int, 3> rooms[2 * n];

    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        rooms[2 * i] = {a, 0, i};
        rooms[2 * i + 1] = {b, 1, i}; 
    }

    std::sort(rooms, rooms + 2 * n, compare);
    std::vector<int> res(n, 0);
    int sol = 0;
    int l = 0, r = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        std::queue<int> q;
        for (int i = 1; i <= mid; i++) {
            q.push(i);
        }
        std::vector<int> res1(n, 0);
        bool cant = false;
        for (int i = 0; i < 2 * n; i++) {
            if (!rooms[i][1]) {
                if (q.empty()) {
                    cant = true;
                    break;
                } else {
                    res1[rooms[i][2]] = q.front();
                    q.pop();
                }
            } else {
                q.push(res1[rooms[i][2]]);
            }
        }
        if (!cant) {
            sol = mid;
            for (int i = 0; i < n; i++) {
                res[i] = res1[i];
            }
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    std::cout << sol << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << res[i] << " ";
    }
    std::cout << "\n";
    return 0;
}