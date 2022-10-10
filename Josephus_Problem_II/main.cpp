#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n, k;
    cin >> n >> k;

    oset<int> numbers;

    for (int i = 1; i <= n; i++) {
        numbers.insert(i);
    }

    int start = 0;
    int N = n;
    for (int i = 1; i <= N; i++) {
        start += k;
        start %= n;
        auto it = numbers.find_by_order(start);
        std::cout << *it << " ";
        numbers.erase(it);
        n--;
    }
    std::cout << std::endl;
    return 0;
}