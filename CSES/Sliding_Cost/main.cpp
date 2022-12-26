#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::multiset<int> left;
    std::multiset<int> right;

    std::vector<int> v;
    std::vector<int> v1;
    for (int i = 0; i < k; i++) {
        int num;
        std::cin >> num;
        v.push_back(num);
        v1.push_back(num);
    }

    std::sort(v.begin(), v.end());
    long long left_sum = 0;
    long long right_sum = 0;
    long long left_num = 0;
    long long right_num = 0;
    for (int i = 0; i < (k + 1) / 2; i++) {
        left.insert(v[i]);
        left_sum += v[i];
        left_num++;
    }

    for (int i = (k + 1) / 2; i < k; i++) {
        right.insert(v[i]);
        right_sum += v[i];
        right_num++;
    }

    int median = *(left.rbegin());
    std::cout << ((median * left_num) - left_sum) + (right_sum - (median * right_num)) << " ";
    for (int i = k; i < n; i++) {
        int num;
        std::cin >> num;
        v1.push_back(num);
        int del_num = v1[i - k];


        int a, b;
        a = -1e9;
        if (left.size())
            a = *(left.rbegin());
        b = 1e9;
        if (right.size())
            b = *(right.begin());
        if (del_num <= a) {
            left_num--;
            left_sum -= del_num;
            left.erase(left.find(del_num));
        } else {
            right_num--;
            right_sum -= del_num;
            right.erase(right.find(del_num));
        }

        while (((int)right.size() - (int)left.size()) > 0) {
            auto st = right.begin();
            left_num++;
            right_num--;
            left_sum += *st;
            right_sum -= *st;
            left.insert(*st);
            right.erase(right.find(*st));

        }

        while (((int)left.size() - (int)right.size()) > 1) {
            auto st = left.rbegin();
            //std::cout << *st << std::endl;
            left_num--;
            right_num++;
            left_sum -= *st;
            right_sum += *st;
            right.insert(*st);
            left.erase(left.find(*st));

        }

        a = -1e9;
        if (left.size())
            a = *(left.rbegin());
        b = 1e9;
        if (right.size())
            b = *(right.begin());
        if (num >= a && num <= b) {
            if (left.size() == right.size()) {
                left_num++;
                left_sum += num;
                left.insert(num);
            } else if(left.size() > right.size()) {
                right_num++;
                right_sum += num;
                right.insert(num);
            } else {
                left_num++;
                left_sum += num;
                left.insert(num);
            }
        } else if (num < a) {
            left.insert(num);
            left_num++;
            left_sum += num;
            while (((int)left.size() - (int)right.size()) > 1) {
                auto st = left.rbegin();
                left_num--;
                right_num++;
                left_sum -= *st;
                right_sum += *st;
                right.insert(*st);
                left.erase(left.find(*st));

            }
        } else if (num > b) {
            right.insert(num);
            right_num++;
            right_sum += num;
            while (((int)right.size() - (int)left.size()) > 0) {
                auto st = right.begin();
                left_num++;
                right_num--;
                left_sum += *st;
                right_sum -= *st;
                left.insert(*st);
                right.erase(right.find(*st));

            }
        }
        median = *(left.rbegin());
        std::cout << ((median * left_num) - left_sum) + (right_sum - (median * right_num)) << ' ';
    }


    return 0;
}