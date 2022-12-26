#include <bits/stdc++.h>


int fw1[200001];

int cnt = 1;
int br, x;
void up() {
    while (br < cnt) {
        fw1[br]++;
        br += (br & -br);
    }
}

int qu() {
    int sum = 0;
    while (x) {
        sum += fw1[x];
        x -= (x & -x);
    }
    return sum;
}


bool compare(const std::pair<std::pair<int, int> , int> &a,const  std::pair<std::pair<int, int> , int> &b) { 
    if (a.first.first == b.first.first) {
        return a.first.second > b.first.second;
    } 
    return a.first.first < b.first.first;
    
}


signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();
    //freopen("input.txt", "r" , stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    std::cin >> n;
    std::vector<int> all;
    std::vector<std::pair<std::pair<int, int> , int> > entry(n);
    std::set<int> set;
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        entry[i].second = i;
        entry[i].first = {a, b};
        set.insert(b);
    }
    std::sort(entry.begin(), entry.end(), compare);

    std::map<int, int> m;

    for (int i : set) {
        m[i] = cnt++;
    }

    int vis1[n];
 
    for (int i = n - 1; i >= 0; i--) {
        x = m[entry[i].first.second];
        vis1[entry[i].second] = qu();
        br = m[entry[i].first.second];
        up();
    }
    for (int i = 0; i < n; i++) {
        std::cout << (vis1[i] > 0) << ' ';
    }
    std::cout << '\n';
    memset(fw1, 0, sizeof(fw1));
    memset(vis1, 0, sizeof(vis1));
    for (int i = 0; i < n; i++) {
        x = m[entry[i].first.second] - 1;
        br = m[entry[i].first.second];
        vis1[entry[i].second] = i - qu();
        up();
    }
    for (int i = 0; i < n; i++) {
        std::cout << (vis1[i] > 0) << ' ';
    }
    std::cout << '\n';
    return 0;
}