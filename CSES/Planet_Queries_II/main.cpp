#include <iostream>
#include <vector>
#include <queue>

int portal[200002];
std::vector<int> r_portal[200002];
int result[200002];
int visited[200002];
int pqvisited[200002];
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, q;
    std::cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int dest;
        std::cin >> dest;
        dest--;
        portal[i] = dest;
        r_portal[dest].push_back(i);
    }
    std::priority_queue<std::pair<int, int>> pq;
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            continue;
        }
        visited[i] = cnt;
        std::vector<int> vec;
        vec.push_back(i);
        int next = i;
        bool cycle = false;
        while (true) {
            next = portal[next];
            if (visited[next] == cnt) {
                cycle = true;
                break;
            } else if (visited[next]) {
                break;
            }
            visited[next] = cnt;
            vec.push_back(next);
        }
        if (cycle) {
            int items = 0;
            for (int j = vec.size() - 1; j >= 0; j--) {
                items += 1;
                if (vec[j] == next) {
                    break;
                }
            }
            for (int j = vec.size() - items; j < vec.size(); j++) {
                result[vec[j]] = items;
                pq.push({result[vec[j]], vec[j]});
            }
        }
        cnt++;
    }

    while (!pq.empty()) {
        std::pair<int, int> top_pair = pq.top();
        pq.pop();


        for (int next : r_portal[top_pair.second]) {
            if (result[next]) {
                continue;
            }
            result[next] = top_pair.first + 1;
            visited[next] = visited[top_pair.second];
            pq.push({top_pair.first + 1, next});
        }
    }
    
    for (int i = 0; i < q; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        if (visited[a] == visited[b]) {
            if (result[a] > result[b]) {
                std::cout << result[a] - result[b] << "\n";
            } else {
                std::cout << -1 << "\n";
            }
        } else {
            std::cout << -1 << "\n";
        }
        
    }
    

}