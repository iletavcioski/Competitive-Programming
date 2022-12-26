#include <iostream>

const long long mod = 1000000007;

int main() {
  int n;
  std::cin >> n;

  long long res = 1;
  for (int i = 0; i < n; i++) {
    res *= 2;
    res %= mod;
  }

  std::cout << res << std::endl;
  return 0;
}
