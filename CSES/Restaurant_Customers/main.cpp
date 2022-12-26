#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <set>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int> > times;
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        times.emplace_back(a, b);
    }
    std::sort(times.begin(), times.end());
    int max = 0;
    int count = 0;
    int currtime = 0;
    std::multiset<int> end_times;
    for (auto &time : times) {
        end_times.insert(time.second);
        currtime = time.first;
        count++;
        while (!end_times.empty() && *end_times.begin() < currtime) {
            end_times.erase(end_times.begin());
            count--;
        }
        max = std::max(max, count);
    }
    std::cout << max << std::endl;
    return 0;
}
