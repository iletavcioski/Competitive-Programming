#include <iostream>
#include <string>

long long dp(std::string num_one, std::string num_two, bool limit_upper) {
    long long res = 0;

    for (int i = 0; i < num_one.size(); i++) {
        if (i > 1) {
            if (limit_upper == false && num_two[i - 1] == num_two[i - 2]) {
                break;
            } else if (limit_upper && num_one[i - 1] == num_one[i - 2]) {
                break;
            }
        }
        long long multiply = 1;
        for (int j = i + 1; j < num_one.size(); j++) {
            multiply *= 9;
        }
        long long multiplier = num_two[i] - num_one[i];
        if (i == 0 && num_one.size() == 1) {
            multiplier++;
        }
        if (i > 0) {
            if (limit_upper == false) {
                if (i < num_one.size() - 1) {
                    multiplier = num_two[i] - num_one[i];
                    if (num_two[i - 1] >= num_one[i] && num_two[i - 1] < num_two[i]) {
                        multiplier--;
                    }
                } else {
                    multiplier = num_two[i] - num_one[i] + 1;
                    if (num_two[i - 1] >= num_one[i] && num_two[i - 1] <= num_two[i]) {
                        multiplier--;
                    }
                }
            } else {
                if (i < num_one.size() - 1) {
                    multiplier = num_two[i] - num_one[i];
                    if (num_one[i - 1] > num_one[i] && num_one[i - 1] <= num_two[i]) {
                        multiplier--;
                    }
                } else {
                    multiplier = num_two[i] - num_one[i] + 1;
                    if (num_one[i - 1] >= num_one[i] && num_one[i - 1] <= num_two[i]) {
                        multiplier--;
                    }
                }

            }
        }


        multiply *= multiplier;
        res += multiply;
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
        result += dp(first_number, first_number_boundary_high, true);
        result += dp(second_number_boundary_low, second_number, false);
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
            result += dp(first_number, second_number, false);
        } else {
            while (first_number_boundary_high.size() < first_number.size()) {
                first_number_boundary_high += '9';
            }

            while (second_number_boundary_low.size() < second_number.size()) {
                second_number_boundary_low += '0';
            }

            result += dp(first_number, first_number_boundary_high, true);
            result += dp(second_number_boundary_low, second_number, false);
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