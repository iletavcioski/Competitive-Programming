#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

long long fenwick_tree[200001];
int n, q;

struct query {
    int l, r, index;
};

bool compare(query a, query b) {
    if (a.l != b.l) {
        return a.l < b.l;
    }
    return a.r < b.r;
}

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

    std::vector<int> array;
    array.resize(n + 1);
    std::vector<long long> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        std::cin >> array[i];
        prefix[i] = prefix[i - 1] + array[i];
    }

    std::vector<query> queries;
    std::vector<long long> solution(q + 1, 0);

    for (int i = 0; i < q; i++) {
        int left, right;
        std::cin >> left >> right;
        queries.push_back({left, right, i + 1});
    }

    std::sort(queries.begin(), queries.end(), compare);
    std::reverse(queries.begin(), queries.end());
    std::deque<std::pair<int, int> > deque;
    deque.push_back({1000000001, n + 1});

    for (query q : queries) {
        int left = q.l;
        int right = q.r;
        if (left == right) {
            solution[q.index] = 0;
            continue;
        }
        int current = deque[0].second - 1;
        while (current >= left) {
            while (array[current] > deque[0].first) {
                int up_value = -deque[0].first * (deque[1].second - deque[0].second - 1);
                update(deque[0].second, up_value);
                deque.pop_front();
            }
            deque.push_front({array[current], current});
            int up_value = deque[0].first * (deque[1].second - deque[0].second - 1);
            update(deque[0].second, up_value);
            current--;
        }

        int l = 0, r = deque.size() - 1;
        int pos = l;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (deque[mid].second <= right) {
                pos = std::max(pos, mid);
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        long long sum_maxi = query_(deque[pos].second - 1) - query_(deque[0].second - 1);
        long long sum_prefix = prefix[deque[pos].second - 1] - prefix[deque[0].second];
        long long additional_part_maxi = ((right - deque[pos].second) * deque[pos].first);
        long long additional_part_prefix = (prefix[right] - prefix[deque[pos].second]);
        solution[q.index] = sum_maxi - sum_prefix + additional_part_maxi - additional_part_prefix;
    }

    for (int i = 1; i <= q; i++) {
        std::cout << solution[i] << '\n';
    }

    return 0;
}