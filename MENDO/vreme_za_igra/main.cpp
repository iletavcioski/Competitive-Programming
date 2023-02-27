#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int first = n;
    int second = 2 * first;
    int third = 2 * second;
    int fourth = 2 * third;
    std::cout << first + second + third + fourth << "\n";
    return 0;
}