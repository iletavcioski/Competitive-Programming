#include <iostream>
#include <string>

long long dp(std::string num_one, std::string num_two) {
    if (num_one.size() == 1) {
        return num_two[0] - num_one[0] + 1;
    }

    long long dp[10][10][2];
    for (int i = 0; i < 10; i++) {
        for (int k = 0; k < 10; k++) {
            for (int j = 0; j < 2; j++) {
                dp[i][k][j] = 0;
            }
        }
    }

    int first = 0;
    int second = 1;

    for (int i = 0; i < num_one.size() - 1; i++) {
        if (i == 0) {
            for (int j = num_one[i] - '0'; j <= num_two[i] - '0'; j++) {
                if (j == num_one[i] - '0' && j == num_two[i] - '0') {
                    for (int k = num_one[i + 1] - '0'; k <= num_two[i + 1] - '0'; k++) {
                        if (k == j) {
                            continue;
                        }
                        dp[j][k][first] = 1;
                    }
                } else if (j == num_one[i] - '0') {
                    for (int k = num_one[i + 1] - '0'; k <= 9; k++) {
                        if (k == j) {
                            continue;
                        }
                        dp[j][k][first] = 1;
                    }
                } else if (j == num_two[i] - '0') {
                    for (int k = 0; k <= num_two[i + 1] - '0'; k++) {
                        if (k == j) {
                            continue;
                        }
                        dp[j][k][first] = 1;
                    }
                } else {
                    for (int k = 0; k <= 9; k++) {
                        if (k == j) {
                            continue;
                        }
                        dp[j][k][first] = 1;
                    }
                }
            }
        } else {
            for (int ii = 0; ii <= 9; ii++) {
                for (int jj = 0; jj <= 9; jj++) {
                    dp[ii][jj][second] = 0;
                }
            }
            for (int l = 0; l <= 9; l++) {
                for (int j = num_one[i] - '0'; j <= num_two[i] - '0'; j++) {
                    if (j == num_one[i] - '0' && j == num_two[i] - '0') {
                        for (int k = num_one[i + 1] - '0'; k <= num_two[i + 1] - '0'; k++) {
                            if (k == j) {
                                continue;
                            }
                            dp[j][k][second] += dp[l][j][first];
                        }
                    } else if (j == num_one[i] - '0') {
                        for (int k = num_one[i + 1] - '0'; k <= 9; k++) {
                            if (k == j) {
                                continue;
                            }
                            dp[j][k][second] += dp[l][j][first];
                        }
                    } else if (j == num_two[i] - '0') {
                        for (int k = 0; k <= num_two[i + 1] - '0'; k++) {
                            if (k == j) {
                                continue;
                            }
                            dp[j][k][second] += dp[l][j][first];
                        }
                    } else {
                        for (int k = 0; k <= 9; k++) {
                            if (k == j) {
                                continue;
                            }
                            dp[j][k][second] += dp[l][j][first];
                        }
                    }
                }
            }
            int t = first;
            first = second;
            second = t;
        }
    }
    long long res = 0;
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            res += dp[i][j][first];
        }
    }
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    std::string first_number;
    std::string second_number;

    std::cin >> first_number >> second_number;

    long long result = 0;

    
    for (int i = first_number.size() + 1; i < second_number.size(); i++) {
        long long multiply = 9;
        long long current = 1;
        for (int j = 0; j < i; j++) {
            current *= multiply;
        }
        result += current;
    }

    std::string first_number_boundary_high = "";
    std::string second_number_boundary_low = "";

    if (first_number.size() < second_number.size()) {
        for (int i = 0; i < first_number.size(); i++) {
            first_number_boundary_high += '9';
        }
        second_number_boundary_low += '1';
        for (int i = 0; i < second_number.size() - 1; i++) {
            second_number_boundary_low += '0';
        }
        result += dp(first_number, first_number_boundary_high);
        result += dp(second_number_boundary_low, second_number);
    }

    
    if (first_number.size() == second_number.size()) {
        int digit = 0;
        
        while (first_number[digit] == second_number[digit] && digit < first_number.size()) {
            first_number_boundary_high += first_number[digit];
            second_number_boundary_low += second_number[digit];
            digit++;
        }

        if (digit < first_number.size()) {
            first_number_boundary_high += first_number[digit];
            second_number_boundary_low += second_number[digit];
        }

        if (first_number_boundary_high.size() == first_number.size()) {
            result += dp(first_number, second_number);
        } else {
            while (first_number_boundary_high.size() < first_number.size()) {
                first_number_boundary_high += '9';
            }

            while (second_number_boundary_low.size() < second_number.size()) {
                second_number_boundary_low += '0';
            }

            result += dp(first_number, first_number_boundary_high);
            result += dp(second_number_boundary_low, second_number);
            long long multiply = 9;
            long long current = 1;
            for (int j = 0; j < second_number.size() - 1; j++) {
                current *= multiply;
            }
            for (int i = first_number[0] - '0' + 1; i < second_number[0] - '0'; i++) {
                result += current;
            }
        }
    }

    std::cout << result << std::endl;
    return 0;
}