#include <iostream>
#include <vector>

std::vector<std::pair<int, int> > res;

void rec(int n, int from, int to, int through) {
    if (n == 1) {
        res.push_back({from, to});
        return;
    }

    rec(n - 1, from, through, to);
    rec(1, from, to, through);
    rec(n - 1, through, to, from);
    return;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    
    
    int n;
    std::cin >> n;

    rec(n, 1, 3, 2);
    std::cout << res.size() << std::endl;

    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i].first << " " << res[i].second << "\n"; 
    }
    return 0;
}