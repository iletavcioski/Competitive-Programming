#include <iostream>

int ft[200001];
int ar[200001];

void update(int x, int v) {
    while (x <= 200000) {
        ft[x] += v;
        x += (-x & x);
    }
}

int query(int x) {
    int sum = 0;
    while (x) {
        sum += ft[x];
        x -= (-x & x);
    }
    return sum;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n;
    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        std::cin >> ar[i];
        update(i, 1);
    }

    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        int l = 1, r = n;
        int idx = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (query(mid) >= num) {
                r = mid - 1;
                idx = mid;
            } else if (query(mid) < num) {
                l = mid + 1;
            } 
        }
        //if (idx == -1)
        std::cout << ar[idx] << ' ';
        update(idx, -1);
    }
    std::cout << '\n';

    return 0;
}