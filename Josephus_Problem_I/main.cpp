#include <iostream>
#include <queue>

int main() {
    int n;
    std::cin >> n;

    std::queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    while (!q.empty()) {
        if (q.size() == 1) {
            std::cout << q.front() << std::endl;
            break;
        }
        int first = q.front();
        q.pop();
        int second = q.front();
        q.pop();
        q.push(first);
        std::cout << second << " ";
    }

    return 0;
}