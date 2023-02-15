#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <queue>

std::map<std::pair<int, int>, int> map;
std::map<std::pair<int, int>, bool> sol;
std::vector<std::pair<int, int> > crossings;
int result = 0;

bool same_distance(std::pair<int, int> a, std::pair<int, int> b, std::pair<int, int> t) {
    if ((abs(a.first - t.first) + abs(a.second - t.second)) == (abs(t.first - b.first) + abs(t.second - b.second))) {
        return true;
    }
    return false;
}

std::pair<int, int> find_middle(std::pair<int, int> a, std::pair<int, int> b) {
    if ((abs(a.first - b.first) + abs(a.second - b.second)) % 2) {
        return {-1, -1};
    }

    int dx = abs(a.first - b.first) / 2;
    int dy = abs(a.second - b.second) / 2;

    int fx, fy;
    if (a.second < b.second) {
        fx = a.first + dx;
        fy = a.second + dy;
    } else if (a.second == b.second) {
        if (a.first < b.first) {
            fx = a.first + dx;
            fy = a.second + dy;
        } else {
            fx = b.first + dx;
            fy = b.second + dy;
        }
    } else {
        fx = b.first + dx;
        fy = b.second + dy;
    }

    if (same_distance(a, b, {fx, fy})) {
        return {fx, fy};
    } else if (same_distance(a, b, {fx + 1, fy})) {
        return {fx + 1, fy};
    } else if (same_distance(a, b, {fx, fy + 1})) {
        return {fx, fy + 1};
    } else if (same_distance(a, b, {fx + 1, fy - 1})) {
        return {fx + 1, fy - 1};
    } else if (same_distance(a, b, {fx + 1, fy + 1})) {
        return {fx + 1, fy + 1};
    } else if (same_distance(a, b, {fx - 1, fy})) {
        return {fx - 1, fy};
    } else if (same_distance(a, b, {fx, fy - 1})) {
        return {fx, fy - 1};
    } else if (same_distance(a, b, {fx - 1, fy + 1})) {
        return {fx - 1, fy + 1};
    } else if (same_distance(a, b, {fx - 1, fy - 1})) {
        return {fx - 1, fy - 1};
    }
    
    return {fx, fy};
}

int distance(std::pair<int, int> a, std::pair<int, int> b) {
    return (abs(a.first - b.first) + abs(a.second - b.second));
}

bool check(std::pair<int, int> a, int dist) {
    for (auto p : crossings) {
        if (distance(a, p) < dist) {
            return false;
        }
    }
    return true;
}

void bfs(int sx, int sy, int h, int v, int cnt, std::pair<int, int> a, std::pair<int, int> b) {
    int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
    int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

    std::queue<int> qx;
    std::queue<int> qy;

    qx.push(sx);
    qy.push(sy);


    while (!qx.empty()) {
        int tx = qx.front();
        qx.pop();
        int ty = qy.front();
        qy.pop();

        for (int i = 0; i < 8; i++) {
            int nx = tx + dx[i];
            int ny = ty + dy[i];

            if (nx >= 1 && ny >= 1 && nx <= h && ny <= v && map[{nx, ny}] != cnt && same_distance(a, b, {nx, ny})) {
                if (!sol[{nx, ny}] && check({nx, ny}, distance({nx, ny}, a))) {
                    //std::cout << nx << " -- " << ny << std::endl;
                    sol[{nx, ny}] = true;
                    result++;
                }
                map[{nx, ny}] = cnt;
                qx.push(nx);
                qy.push(ny);
            }
        }
    }

}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int h, v;
    std::cin >> h >> v;

    int n;
    std::cin >> n;



    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;

        crossings.push_back({a, b});
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            std::pair<int, int> mid = find_middle(crossings[i], crossings[j]);
            if (mid.first == -1) {
                continue;
            }

            if (same_distance(crossings[i], crossings[j], mid)) {
                int sx = mid.first, sy = mid.second;
                // std::cout << i << " " << j << std::endl;
                if (i == 1 && j == 3) {
                    int kk = 0;
                }
                bfs(sx, sy, h, v, ++cnt, crossings[i], crossings[j]);
            }

        }
    }

    std::cout << result << std::endl;
    return 0;
}