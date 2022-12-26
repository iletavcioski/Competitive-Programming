#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  if (((n * (n + 1)) / 2) % 2 == 0) {
    std::cout << "YES" << std::endl;
    std::vector<int> a;
    std::vector<int> b;
    long long suma = 0;
    long long sumb = 0;
    for (int i = n; i >= 1; i--) {
      if (suma <= sumb) {
        suma += i;
        a.push_back(i);
      } else {
        sumb += i;
        b.push_back(i);
      }
    }

    std::cout << a.size() << std::endl;
    for (int i = 0; i < a.size(); i++) {
      std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    std::cout << b.size() << std::endl;
    for (int i = 0; i < b.size(); i++) {
      std::cout << b[i] << " ";
    }
    std::cout << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }
}
