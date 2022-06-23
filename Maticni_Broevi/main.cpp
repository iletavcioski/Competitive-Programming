#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, m;
    std::cin >> n >> m;

    long long result = 1;
    for (int i = 0; i < n; i++) {
        result *= 10;
    }

    long long palindroms_count = 1;

    for (int i = 0; i < ((n + 1) / 2); i++) {
        palindroms_count *= 10;
    }

    result -= palindroms_count;

    std::vector<std::string> numbers;
    for (int i = 0; i < m; i++) {
        std::string number;
        std::cin >> number;
        numbers.push_back(number);
    }

    std::sort(numbers.begin(), numbers.end());

    std::vector<bool> vis(m, 0);
    for (int i = 0; i < m; i++) {
        if (!vis[i]) {
            for (int j = i + 1; j < m; j++) {
                if (!vis[j] and numbers[j].substr(0, numbers[i].size()) == numbers[i]) {
                    vis[j] = true;
                }
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (!vis[i]) {
            long long delete_number = 1;
            for (int j = 0; j < n - numbers[i].size(); j++) {
                delete_number *= 10;
            }
            long long add_pal = 1;
            int nums = (n - ((int)numbers[i].size() * 2));
            nums++;
            nums /= 2;
            nums = std::max(nums, 0);
            for (int j = 0; j < nums; j++) {
                add_pal *= 10;
            }
            result -= delete_number;
            std::string check_num = numbers[i];
            std::reverse(check_num.begin(), check_num.end());

            if ((numbers[i].size() * 2 <= n) || (numbers[i].size() == n && check_num == numbers[i]))
                result += add_pal;
            else if ((numbers[i].size() < n) && (numbers[i].size() * 2 > n) ) {
                std::string new_check = "";

                for (int j = 0; j < n - (int)numbers[i].size(); j++) {
                    new_check += numbers[i][j];
                }
                new_check += check_num;
                std::string next_check = new_check;
                std::reverse(next_check.begin(), next_check.end());
                if (next_check == new_check) {
                    result += add_pal;
                }
            }
        }
    }

    std::cout << result << std::endl;
    return 0;
}