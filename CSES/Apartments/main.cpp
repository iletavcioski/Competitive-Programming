#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> apartments;
    std::vector<int> applicants;
    apartments.resize(m);
    applicants.resize(n);

    for (int i = 0; i < n; i++) {
        std::cin >> applicants[i];
    }

    for (int i = 0; i < m; i++) {
        std::cin >> apartments[i];
    }

    std::sort(apartments.begin(), apartments.end());
    std::sort(applicants.begin(), applicants.end());

    int i = 0;
    int j = 0;
    int count = 0;
    while (i < n && j < m) {
        if (applicants[i] - k > apartments[j]) {
            j++;
            continue;
        }

        if (applicants[i] + k < apartments[j]) {
            i++;
            continue;
        }

        if (std::abs(applicants[i] - apartments[j]) <= k) {
            count++;
            i++;
            j++;
            continue;
        }

    }

    std::cout << count << std::endl;
    return 0;
}
