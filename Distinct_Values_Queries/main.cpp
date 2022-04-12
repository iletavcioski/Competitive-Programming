#include <bits/stdc++.h>

typedef long long ll;

std::map<int, int> map;
std::vector<int> numbers;

struct query {
    int l;
    int r;
    int bucket;

} queries[200002];

bool comparator(const query &x, const query &y) {
    if (x.bucket == y.bucket) {
        return x.r < y.r;
    }
    return x.bucket < y.bucket;
}

void add(int pos) {
    map[numbers[pos]]++;    
}

void remove(int pos) {
    map[numbers[pos]]--;
    if (map[numbers[pos]] == 0) {
        map.erase(numbers[pos]);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n;
    std::cin >> n;

    int q;
    std::cin >> q;

    
    return 0;

}