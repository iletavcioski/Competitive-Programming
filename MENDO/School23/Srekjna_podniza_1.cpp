#include <iostream>
#include <vector>
#include <string>
#include <map>
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();
 
    int n, k;
    std::cin >> n;
 
    std::vector<int> v;
 
    v.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }
 
    int maxi = 0;
    int l = 0, r = 0;
    int cnt = 0;
    while (l < n && r < n) {
       if (cnt < 3) {
           if (v[r] == 3) {
               cnt++;
           }
           r++;
       } else if (cnt > 3) {
           if (v[l] == 3) {
               cnt--;
           }
           l++;
       } else {
           maxi = std::max(maxi, r - l);
           if (v[r] == 3) {
               cnt++;
           }
           r++;
       }
    }
 
 
 
    if (cnt == 3) {
        maxi = std::max(maxi, r - l);
    }
    std::cout << maxi << std::endl;
    return 0;
}