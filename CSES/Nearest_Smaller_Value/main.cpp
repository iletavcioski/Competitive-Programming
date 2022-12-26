#include <iostream>
#include <stack>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n;
    std::cin >> n;

    std::stack<std::pair<int, int> > stack;
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;

        int idx = 0;
        while (!stack.empty()) {
            if (stack.top().first >= num) {
                stack.pop();
            } else {
                idx = stack.top().second;
                break;
            }
        }
        stack.push({num, i + 1});
        std::cout << idx << " ";
    }
    std::cout << "\n";

    

    

    return 0;
}