#include <iostream>
#include <vector>


std::vector<int> tree[200002];
int lca[200002][19];

void dfs(int x, int prev) {
    for (int next : tree[x]) {
        if (next == prev) {
            continue;
        }
        lca[next][0] = x;
        dfs(next, x); 
    }
}

int query(int a, int b) {
    for (int j = 18; j >= 0; j--) {
        if (b < (1 << j)) {
            continue;
        }

        if (a == -1) {
            continue;
        }
        a = lca[a][j];
        b -= (1 << j);
    }
    return a;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, q;
    std::cin >> n >> q;

    for (int i = 2; i <= n; i++) {
        int a;
        std::cin >> a;
        tree[a].push_back(i);
    }

    for (int i = 0; i <= 18; i++) {
        for (int j = 1; j <= n; j++) {
            lca[j][i] = -1;
        }
    }

    dfs(1, 0);

    for (int i = 1; i <= 18; i++) {
        for (int j = 1; j <= n; j++) {
            if (lca[j][i - 1] != -1) 
                lca[j][i] = lca[lca[j][i - 1]][i - 1];
        }
    }

    while (q--) {
        int a, b;
        std::cin >> a >> b;
        std::cout << query(a, b) << std::endl;
    }
    return 0;
}