#include <iostream>

class HouseOfCards {
    public: 
    long long count(int cards) {
        long long c = cards;
        return ((c * (c + 1LL)) + ((c - 1) * c / 2LL));
    }
};

int main() {
    HouseOfCards h;
    std::cout << h.count(2) << "\n";
}