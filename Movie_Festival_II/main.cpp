#include <iostream>
#include <array>
#include <algorithm>
#include <set>

bool compare(const std::array<int, 2> &a, const std::array<int,2 > &b) {
	if (a[1] == b[1]) {
		return a[0] < b[0];
	}
	return a[1] < b[1];
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();

	int n, k;
	std::cin >> n >> k;
	
	std::array<int, 2> movies[n];

	for (int i = 0; i < n; i++) {
		std::cin >> movies[i][0] >> movies[i][1];
	}
	
	std::multiset<int> set;

	for (int i = 0; i < k; i++) {
		set.insert(0);
	}
	
	std::sort(movies, movies + n, compare);
	int res = 0;
	for (int i = 0; i < n; i++) {
		int start = movies[i][0];
		int end = movies[i][1];
		
		auto it = set.upper_bound(start);
		if (it != set.begin()) {
			it--;
			set.erase(it);
			set.insert(end);
			res++;
		}
	}

	std::cout << res << '\n';

	return 0;
}
