#include <iostream>
#include <vector>

typedef long long ll;

const ll mod = 1000000007;

std::vector<std::vector<ll> > multiply(std::vector<std::vector<ll> > a, std::vector<std::vector<ll> > b) {
    std::vector<ll> vec(a[0].size(), 0);
    std::vector<std::vector<ll> > res(a.size(), vec);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < b.size(); k++) {
                res[i][j] += (a[i][k] * b[k][j]) % mod;
                res[i][j] %= mod;
            }
        }
    }

    return res;
}
std::vector<std::vector<ll> > power(std::vector<std::vector<ll> > matrix, ll n) {
    if (n == 1) {
        return matrix;
    }

    std::vector<std::vector<ll> > res;
    std::vector<std::vector<ll> > half = power(matrix, n / 2);
    res = multiply(half, half);
    if (n % 2) {
        res = multiply(res, matrix);
    }

    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    std::vector<std::vector<ll> > matrix = {
        {1, 1},
        {1, 0}
    };
    ll n;
    std::cin >> n;

    if (n == 0) {
        std::cout << 0 << "\n";
    } else if (n == 1) {
        std::cout << 1 << "\n";
    } else {
        std::vector<std::vector<ll> > pow = power(matrix, n - 1);
        std::cout << pow[0][0] << "\n";
    }
    return 0;
}