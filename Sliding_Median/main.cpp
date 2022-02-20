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
    for (int i = 0; i < (k + 1) / 2; i++) {
        left.insert(v[i]);
    }

    for (int i = (k + 1) / 2; i < k; i++) {
        right.insert(v[i]);
    }

    std::cout << *(left.rbegin()) << ' ';
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
            left.erase(left.find(del_num));
        } else {
            right.erase(right.find(del_num));
        }

        while (((int)right.size() - (int)left.size()) > 0) {
            auto st = right.begin();
            left.insert(*st);
            right.erase(right.find(*st));

        }

        while (((int)left.size() - (int)right.size()) > 1) {
            auto st = left.rbegin();
            //std::cout << *st << std::endl;
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
                left.insert(num);
            } else if(left.size() > right.size()) {
                right.insert(num);
            } else {
                left.insert(num);
            }
        } else if (num < a) {
            left.insert(num);
            while (((int)left.size() - (int)right.size()) > 1) {
                auto st = left.rbegin();
                right.insert(*st);
                left.erase(left.find(*st));

            }
        } else if (num > b) {
            right.insert(num);
            while (((int)right.size() - (int)left.size()) > 0) {
                auto st = right.begin();
                left.insert(*st);
                right.erase(right.find(*st));

            }
        }

        std::cout << *(left.rbegin()) << ' ';
    }


    return 0;
}