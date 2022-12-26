#include <iostream>

int main() {
  int t;
  std::cin >> t;

  while (t--) {
    int a, b;
    std::cin >> a >> b;

    int min = std::min(a, b);
    int max = std::max(a, b);

    if (max - min <= min && 2 * (max - min) <= max) {
      int del = max - min;
      min -= del;
      max -= 2*del;
      if (max % 3 == 0) {
        std::cout << "YES" << std::endl;
      } else {
        std::cout << "NO" << std::endl;
      }
    } else {
      std::cout << "NO" << std::endl;
    }
  }
  return 0;
}
