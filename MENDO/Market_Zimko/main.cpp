#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n;
    std::cin >> n;

    std::vector<int> v(n + 1, -1);
    std::vector<int> before(n + 1, -1);
   
    int last = 0;

    for (int i = 1; i <= n; i++) {
        char a;
        std::cin >> a;
        if (a == 'K') {
            v[last] = i;
            before[i] = last;
            last = i;
        } else {
            int pos;
            std::cin >> pos;

            int bef = before[pos];
            v[bef] = i;
            before[i] = bef;
            v[i] = pos;
            before[pos] = i;
        }
    }

    int idx = 0;
    int count = 0;
    std::vector<int> results(n + 1, 0);
    while (v[idx] != -1) {
        idx = v[idx];
        count++;
        results[idx] = count;
    }

    for (int i = 1; i <= n; i++) {
        std::cout << results[i] << "\n";
    }

    return 0;
}