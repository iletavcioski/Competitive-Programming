#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n;
    std::cin >> n;

    int q;
    std::cin >> q;
    std::vector<int> vis(n + 1, 0);
    std::vector<int> arr;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
        vis[arr[i]] = i;
    }

    int cnt = 1;
    int pos = -1;
    for (int i = 1; i <= n; i++) {
        if (vis[i] > pos) {
            pos = vis[i];
        } else {
            cnt++;
            pos = vis[i];
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        std::cin >> a >> b;
        if (a == b) {
            std::cout << cnt << std::endl;
            continue;
        }
        if (a > b) {
            std::swap(a, b);
        }
        a--;
        b--;
        int a1 = a;
        int b1 = b;
        a = arr[a];
        b = arr[b];
        if (a > b) {
            std::swap(a, b);
        }
        int ima1 = 0;
        if (a > 1 && vis[a] < vis[a - 1])
            ima1++;
        if ( vis[a] > vis[a + 1])
            ima1++;
        if (b - a > 1 && vis[b - 1] > vis[b])
            ima1++;
        if (b < n && vis[b] > vis[b + 1])
            ima1++;
        a = a1;
        b = b1;

        std::swap(arr[a], arr[b]);
        vis[arr[a]] = a;
        vis[arr[b]] = b;
        a = arr[a];
        b = arr[b];
        if (a > b) {
            std::swap(a, b);
        }
        int ima2 = 0;
        if (a > 1 && vis[a] < vis[a - 1])
            ima2++;
        if ( vis[a] > vis[a + 1])
            ima2++;
        if (b - a > 1 && vis[b - 1] > vis[b])
            ima2++;
        if (b < n && vis[b] > vis[b + 1])
            ima2++;


        cnt += (ima2 - ima1);
        std::cout << cnt << "\n";
    }
    return 0;
}