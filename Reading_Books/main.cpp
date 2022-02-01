#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> books;
    books.resize(n);

    for (int i = 0; i < n; i++) {
        std::cin >> books[i];
    }

    std::sort(books.begin(), books.end());
    std::reverse(books.begin(), books.end());

    long long a = 0;
    long long b = 0;

    std::vector<int> books_a;
    std::vector<int> books_b;

    for (int i = 0; i < n; i++) {
        if (a <= b) {
            a += books[i];
            books_a.push_back(books[i]);
        } else {
            b += books[i];
            books_b.push_back(books[i]);
        }
    }
    long long res = std::max(a, b) * 2;
    if (a > b) {
        std::sort(books_a.begin(), books_a.end());
        long long dif = b;
        int pos = 0;
        while (dif >= 0 && pos < books_a.size()) {
            dif -= books_a[pos];
            if (dif < 0) {
                break;
            }
            res -= books_a[pos];
            pos++;
        }
    } else if (a < b) {
        std::sort(books_b.begin(), books_b.end());
        long long dif = a;
        int pos = 0;
        while (dif >= 0 && pos < books_b.size()) {
            dif -= books_b[pos];
            if (dif < 0) {
                break;
            }
            res -= books_b[pos];
            pos++;
        }
    }

    std::cout << res << std::endl;
    return 0;
}