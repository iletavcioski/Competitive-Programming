#include <string>
#include <vector>
#include <iostream>
using namespace std;

typedef long long ll;

class FlowerGarden
{
  public:
  const ll mod = 1000000007;
    vector<vector<ll> > multiply(vector<vector<ll> > a, vector<vector<ll> > b) {
        vector<vector<ll> > mul = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                mul[i][j] = 0;
                for (int k = 0; k < 3; k++) {
                    mul[i][j] += a[i][k]*b[k][j];
                    mul[i][j] %= mod;
                }
            }
        }
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                a[i][j] = mul[i][j]; 
                a[i][j] %= mod;
            }
        }
        return a;
    }

    vector<vector<ll> > power(vector<vector<ll> > F, ll n, ll a, ll b) {
        vector<vector<ll> > M = {{b, a, 0}, {1, 0, 0}, {0, 1, 0}};
        if (n == 1) {
            return F;
        }
        vector<vector<ll> > v = power(F, n / 2LL, a, b);
        vector<vector<ll> > v2 = multiply(v, v);
        if (n % 2LL != 0LL) {
            v2 = multiply(v2, M);
        }
        return v2;
    }

    vector<vector<ll> > findNthTerm(ll n, ll first, ll second, ll a, ll b) {
 
        vector<vector<ll> > F = {{b, a, 0}, {1, 0, 0}, {0, 1, 0}} ;
 
    
        return power(F, n - 2, a, b);
}
    int getFlowerPetals(int first, int second, int a, int b, int n)
    {
        if (n == 1) {
            return (first % mod);
        } else if (n == 2) {
            return (second % mod);
        }
      vector<vector<ll> > res =  findNthTerm(n, first, second, a, b);
      return (((ll)(res[0][0] * second)  % mod) + ((ll)(res[0][0] * first)) % mod) % mod;
  }
};

int main() {
    FlowerGarden b = FlowerGarden();
    cout << b.getFlowerPetals(10, 7, 3, 3, 3) << endl;
}
