#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> books;
    books.resize(n);

    long long max = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> books[i];
        sum += books[i];
        max = std::max(max, (long long)books[i]);
    }

    

    std::cout << std::max(2 * max, sum) << std::endl;
    return 0;
}