#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

long long fenwick_tree[200001];
long long fen_arr[200001];
int n, q;

void update(int i, long long val) {
    while (i <= n) {
        fenwick_tree[i] += val;
        i += (i & (-i));
    }
}

long long query_(int i) {
    long long res = 0;
    while (i >= 1) {
        res += fenwick_tree[i];
        i -= (i & (-i));
    }
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    std::cin >> n >> q;

    std::vector<long long> array;
    array.resize(n + 1);
    std::vector<long long> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        std::cin >> array[i];
        prefix[i] = prefix[i - 1] + array[i];
    }

    std::vector<std::vector<std::pair<long long, int> > > queries;
    std::vector<std::pair<long long, int> > vec;
    queries.insert(queries.begin(), n + 1, vec);
    std::vector<long long> solution(q + 1, 0);

    for (int i = 0; i < q; i++) {
        int left, right;
        std::cin >> left >> right;
        queries[left].push_back({right, i + 1});
    }

    std::vector<std::pair<long long, int> > maxes;
    int num_maximums = 0;

    for (long long i = n; i >= 1; i--) {
        while (!maxes.empty() && maxes.back().first <= array[i]) {
            update(num_maximums, -fen_arr[num_maximums]);
            fen_arr[num_maximums] = 0;
            num_maximums--;
            maxes.pop_back();
        }
        long long last_pos = n + 1;
        if (!maxes.empty()) {
            last_pos = maxes.back().second;
        }

        num_maximums++;

        maxes.push_back({array[i], i});
        update(num_maximums, (long long)(array[i] * (last_pos - i)) - fen_arr[num_maximums]);
        fen_arr[num_maximums] = (long long)array[i] * (last_pos - i);
        for (auto &[right, query_index] : queries[i]) {
            int l = 0;
            int r = num_maximums - 1;
            int pos = 0;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (maxes[mid].second <= right) {
                    pos = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            if (i == right) {
                bool cc = true;
            }

            long long sum1 = query_(num_maximums) - query_(pos + 1);
            long long sum2 = (long long)(right + 1 - std::max((long long)maxes[pos].second, i)) * maxes[pos].first;
            long long prefixSum = prefix[right] - prefix[i - 1];
            solution[query_index] = sum1 + sum2 - prefixSum;

        }
    }

    for (int i = 1; i <= q; i++) {
        std::cout << solution[i] << '\n';
    }

    return 0;
}