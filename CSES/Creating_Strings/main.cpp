#include <iostream>
#include <string>
#include <set>

std::string s;
std::set<std::string> set;

std::string temp = "";


void rec(std::string mom, int bitmask) {
    //std::cout << s << std::endl;
    //std::cout << bitmask << std::endl;
    if (bitmask == (1 << s.size()) - 1) {
        //std::cout << "vleze" << std::endl;
        set.insert(mom);
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        if (!(bitmask & (1 << i))) {
            rec(mom + s[i], bitmask | (1 << i));
        }
    }

}

int main() {
    std::cin >> s;
    rec("", 0);

    std::cout << set.size() << std::endl;
    for (std::string ss : set) {
        std::cout << ss << std::endl;
    }
    return 0;
}