#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, k;
    std::cin >> n >> k;

    int cur = k % n;

    std::set<int> set; 
    for (int i = 1; i <= n; i++) {
        int num;
        std::cin >> num;
        set.insert(num);
    }
    
    return 0;
}