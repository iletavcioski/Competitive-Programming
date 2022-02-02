#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    int m;
    std::cin >> m;

    std::set<int> set;
    std::vector<int> v;
    std::vector<int> inv;
    std::vector<int> res;
    set.insert(0);
    set.insert(n);
    v.push_back(0);
    v.push_back(n);
    for (int i = 0; i < m; i++) {
        int num;
        std::cin >> num;
        set.insert(num);
        v.push_back(num);
        inv.push_back(num);

    }
    std::reverse(inv.begin(), inv.end());
    std::sort(v.begin(), v.end());
    int max = 0;
    for (int i = 0; i < v.size() - 1; i++) {
        max = std::max(max, v[i + 1] - v[i]);
    }
    res.push_back(max);

    for (int i = 0; i < inv.size(); i++) {
        auto it = set.find(inv[i]);
        auto it1 = it;
        auto it2 = it;
        it1++;
        it2--;
        max = std::max(max, *(it1) - *(it2));
        set.erase(it);
        res.push_back(max);
    }
    std::reverse(res.begin(), res.end());
    for (int i = 1; i < res.size(); i++) {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}