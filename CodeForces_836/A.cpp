#include <iostream>
#include <deque>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int t;
    std::cin >> t;
    while (t--) {
        std::string ss;
        std::cin >> ss;

        std::deque<char> v;
        for (int i = 0; i < ss.size(); i++) {
            v.push_back(ss[i]);
            v.push_front(ss[i]);
        }

        std::string res = "";
        for (char a : v) {
            res += a;
        }
        std::cout << res << std::endl;
    }
    return 0;
}