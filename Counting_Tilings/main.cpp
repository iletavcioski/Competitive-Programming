#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
const long long mod = 1000000007;

std::string int3str(int num, int n) {
    std::string str = "";
    while (num > 0) {
        str += ((num % 3) + '0');
        num /= 3;
    }
    while (str.size() < n) str += "0";
    std::reverse(str.begin(), str.end());
    return str;
}
int main() {
    int n, m;
    std::cin >> n >> m;


    long long dp[60000][2];

    int first = 0;
    int second = 1;

    std::queue<int> q;
    for (int i = 0; i < (1 << n); i++) {
        int num = 0;
        int multiply = 1;
        int continuing = 0;
        bool itcant = false;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                num += multiply;
                if (continuing % 2) {
                    itcant = true;
                    break;
                }
                continuing = 0;
            } else {
                continuing++;
            }
            multiply *= 3;
        }
        if (continuing % 2) {
            itcant = true;
        }
        if (!itcant) {
            q.push(num);
            dp[num][first] = 1;
            // std::cout << int3str(num, n) << std::endl;

        }
    }
    // std::cout << "--------------" << std::endl;
    for (int j = 1; j < m; j++) {

        std::queue<int> new_q;

        std::map<int, bool> map;
        while (!q.empty()) {
            int bitmask = q.front();
            q.pop();

            if (bitmask == 80) {
                int bl = 0;
            }

            int num_zeros = 0;
            int multiply = 1;
            int new_bitmask = 0;
            for (int i = 0; i < n; i++) {
                if ((bitmask / multiply) % 3 == 0 || (bitmask / multiply) % 3 == 2) {
                    num_zeros++;
                } else {
                    new_bitmask += 2 * multiply;
                }
                multiply *= 3;
            }
            
            for (int i = 0; i < (1 << num_zeros); i++) {
                int candidate = new_bitmask;
                multiply = 1;
                for (int bit = 0; bit < num_zeros; bit++) {
                    while ((candidate / multiply) % 3 == 2) {
                        multiply *= 3;
                    }
                    if (i & (1 << bit)) {
                        candidate += multiply;
                    }
                    multiply *= 3;
                }
                multiply = 1;
                bool is_candidate = true;
                int consecutive = 0;
                for (int bit = 0; bit < n; bit++) {
                    if ((candidate / multiply) % 3 == 0) {
                        consecutive++;
                    } else {
                        if (consecutive % 2) {
                            is_candidate = false;
                            break;
                        }
                        consecutive = 0;
                    }
                    multiply *= 3;
                }
                if (consecutive % 2) {
                    is_candidate = false;
                }

                if (is_candidate) {
                    // std::cout << int3str(bitmask, n) << " " << bitmask << " " <<  int3str(candidate, n) << " " << candidate << std::endl;
                    if (!map[candidate]) {
                        new_q.push(candidate);
                        map[candidate] = true;
                        dp[candidate][second] = 0;
                        
                    }
                    dp[candidate][second] += dp[candidate][first];
                    dp[candidate][second] %= mod;
                }
            }
        }
        // std::cout << "--------------" << std::endl;
        q = new_q;
        std::swap(first, second);
    }

    long long res = 0;
    while (!q.empty()) {
        int multiply = 1;
        int candidate = q.front();
        q.pop();
        bool is_candidate = true;
        for (int bit = 0; bit < n; bit++) {
            if ((candidate / multiply) % 3 == 1) {
                is_candidate = false;
                break;
            }
            multiply *= 3;
        }

        if (is_candidate) {
            res += dp[candidate][first];
            res %= mod;
        }
    }

    std::cout << res << std::endl;
    return 0;
}