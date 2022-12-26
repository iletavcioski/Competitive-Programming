#include <bits/stdc++.h>

typedef long long ll;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n;
    std::cin >> n;
    std::map<int, int> map;
    
    int max = 1e9 + 1;
    int max_in = -1;
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        map[num]++;
        if (num < max) {
            max = num;
            max_in = i + 1;
        }
    }

    if (map[max] > 1) {
        std::cout << "Still Rozdil\n";
    } else {
        std::cout << max_in << "\n";
    }
    return 0;
}