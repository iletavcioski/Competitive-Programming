#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> nums;
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());
    long long last = 0;

    for (int i = 0; i < n; i++) {
        if (last + 1 - nums[i] >= 0) {
            last += nums[i];
        } else {
            break;
        }
    }
    std::cout << last + 1 << std::endl;
    return 0;
}