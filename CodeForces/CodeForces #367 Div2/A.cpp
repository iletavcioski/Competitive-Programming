#include <bits/stdc++.h>

typedef long long ll;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie();
    std::cin.tie();

    double a, b;
    std::cin >> a >> b;

    int n;
    std::cin >> n;

    double min = 1e9;
    for (int i = 0; i < n; i++) {
        double x, y;
        std::cin >> x >> y;
        double v;
        std::cin >> v;

        min = std::min(min, double(sqrt(double(double(double(x - a) * double(x - a)) + double(double(y - b) * double(y - b)))) / v));
    }

    std::cout << min << "\n";
    return 0;
}