#include <iostream>
#include <algorithm>
#include <unordered_map>

int fw1[400001];

int cnt = 0;
int br, val = 1, x;
void up() {
    while (br < cnt) {
        fw1[br] += val;
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


bool compare(const std::array<int, 3> &a, const std::array<int, 3> &b) {
    if (a[0] < b[0]) {
        return true;
    } else if (a[0] == b[0]) {
        return a[1] > b[1];
    } else {
        return false;
    }
}


int main() {
    int n;
    scanf("%d", &n);

    int all[2 * n];

    std::array<int, 3> entry[n];
    std::array<int, 3> exit[n];

    
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        entry[i] = {a, b, i};
        exit[i] = {b, a, i};
        all[2 * i] = a;
        all[2 * i + 1] = b;
    }

    std::sort(all, all + (2 * n));
    std::unordered_map<int, int> m;
    cnt = 1;
    int prevv = -1;
    for (int i = 0; i < 2 * n; i++) {
        if (i && all[i] == all[i - 1]) {
            continue;
        }
        m[all[i]] = cnt;
        cnt++;
    }


    int vis1[n];
    int vis2[n];

    std::sort(entry, entry + n, compare);
    for (int i = 0; i < n; i++) {
        x = m[entry[i][1]] - 1;
        br = m[entry[i][1]];
        vis2[entry[i][2]] = i - qu();
        up();
    }
    std::fill(fw1, fw1 + cnt, 0);

    std::sort(exit, exit + n, compare);
    for (int i = 0; i < n; i++) {
        x = m[exit[i][1]] - 1;
        vis1[exit[i][2]] = i - qu();
        br = m[exit[i][1]];
        up();
    }


    for (int i = 0; i < n; i++) {
        printf("%d ", vis1[i]);
    }
    printf("\n");
   

    for (int i = 0; i < n; i++) {
        
        printf("%d ", vis2[i]);
    }
    printf("\n");

    return 0;
}