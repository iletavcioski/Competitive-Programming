#include <bits/stdc++.h>

typedef long long ll;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    ll l, r;
    std::cin >> l >> r;

    int num_l = 0LL;
    int num_r = 0LL;

    ll l1 = l;
    ll r1 = r;
    int last_l = 0LL;
    int last_r = 0LL;
    while (l1 > 0LL) {
        num_l++;
        last_l = l1 % 10LL;
        l1 /= 10LL;
    }

    while (r1 > 0LL) {
        num_r++;
        last_r = r1 % 10LL;
        r1 /= 10LL;
    }

    ll res = 0LL;
    for (int i = num_l + 1; i <= num_r - 1; i++) {
        ll middle = 1LL;
        for (int j = 0; j < i - 2; j++) {
            middle *= 10LL;
        }
        middle *= 9LL;
        res += middle;
    }

    if (num_l == num_r) {
        if (last_l == last_r) {
            
            std::vector<int> v;
            l1 = l;
            while (l1 > 0) {
                v.push_back(l1 % 10);
                l1 /= 10;
            }
            if (r == l && v[0] != v[v.size() - 1]) {
                std::cout << 0 << "\n";
                return 0;
            }

            if (r == l && v[0] == v[v.size() - 1]) {
                std::cout << 1 << "\n";
                return 0;
            }
            res = 0;
            if (r > l && v[v.size() - 1] > v[0]) {
                res++;
            }
            //std::cout << res << "\n";
            res += (r - l) / 10;
            res += (v[0] == v[v.size() - 1]);
            std::vector<int> v1;
            r1 = r;
            while (r1 > 0) {
                v1.push_back(r1 % 10);
                r1 /= 10;
            }
            res -= (v[v.size() - 1] > v[0]);
            std::cout << res  << std::endl;
            return 0;
        }

        l1 = l;
        r1 = r;

        ll midl = 1LL;
        ll midr = 1LL;

        for (int i = 0; i < num_l - 2; i++) {
            midl *= 10LL;
        }

        for (int i = 0; i < num_r - 2; i++) {
            midr *= 10LL;
        }
        //std::cout << res << "\n";
        //std::cout << last_l << " " << last_r << "\n";
        midl *= (last_r - last_l - 1);
       
        res += midl;
        
        
        l1 /= 10;
        l1 *= 10;
        l1 += last_l;
        r1 /= 10;
        r1 *= 10;
        r1 += last_r;

        if (l1 >= l) {
            ll mid = 0;
            std::vector<int> v;
            while (l1 > 0) {
                v.push_back(l1 % 10);
                l1 /= 10;
            }
            ll pow = 1;
            ll mid1 = 0;
            for (int i = 1; i < v.size() - 1; i++) {
                mid1 += (v[i] * pow);
                pow *= 10;
            }
            mid += (pow - mid1);
            if (v[0] == v[v.size() - 1]) {
                res += mid;
            }
            
        } else {
            l1 += 10;
            ll mid = 0;
            std::vector<int> v;
            while (l1 > 0) {
                v.push_back(l1 % 10);
                l1 /= 10;
            }
            ll pow = 1;
            ll mid1 = 0;
            for (int i = 1; i < v.size() - 1; i++) {
                mid1 += (v[i] * pow);
                pow *= 10;
            }
            mid += (pow - mid1);
            if (v[0] == v[v.size() - 1] && num_l == v.size()) {
                res += mid;
            }
            
        }
        //std::cout << res << "\n";
        if (r1 <= r) {
            ll mid = 1;
            std::vector<int> v;
            while (r1 > 0) {
                v.push_back(r1 % 10);
                r1 /= 10;
            }
            ll pow = 1;
            for (int i = 1; i < v.size() - 1; i++) {
                mid += (v[i] * pow);
                pow *= 10;
            }
            if (v[0] == v[v.size() - 1]) {
                res += mid;
            }
            
        } else {
            r1 -= 10;
            ll mid = 1;
            std::vector<int> v;
            while (r1 > 0) {
                v.push_back(r1 % 10);
                r1 /= 10;
            }
            ll pow = 1;
            for (int i = 1; i < v.size() - 1; i++) {
                mid += (v[i] * pow);
                pow *= 10;
            }
            if (v[0] == v[v.size() - 1] && num_r == v.size()) {
                res += mid;
            }
            
        }
        std::cout << res << "\n";
        return 0;

    }

    
    l1 = l;
    r1 = r;

    ll midl = 1LL;
    ll midr = 1LL;

    for (int i = 0; i < num_l - 2; i++) {
        midl *= 10LL;
    }

    for (int i = 0; i < num_r - 2; i++) {
        midr *= 10LL;
    }
    //std::cout << res << "\n";
    //std::cout << last_l << " " << last_r << "\n";
    midl *= (9LL - last_l);
    midr *= (last_r - 1LL);
    res += midl;
    
    res += midr;
    //std::cout << res << "\n";
    
    l1 /= 10;
    l1 *= 10;
    l1 += last_l;
    r1 /= 10;
    r1 *= 10;
    r1 += last_r;

    if (l1 >= l) {
        ll mid = 0;
        std::vector<int> v;
        while (l1 > 0) {
            v.push_back(l1 % 10);
            l1 /= 10;
        }
        ll pow = 1;
        ll mid1 = 0;
        for (int i = 1; i < v.size() - 1; i++) {
            mid1 += (v[i] * pow);
            pow *= 10;
        }
        mid += (pow - mid1);
        if (v[0] == v[v.size() - 1]) {
            res += mid;
        }
        
    } else {
        l1 += 10;
        ll mid = 0;
        std::vector<int> v;
        while (l1 > 0) {
            v.push_back(l1 % 10);
            l1 /= 10;
        }
        ll pow = 1;
        ll mid1 = 0;
        for (int i = 1; i < v.size() - 1; i++) {
            mid1 += (v[i] * pow);
            pow *= 10;
        }
        mid += (pow - mid1);
        if (v[0] == v[v.size() - 1] && num_l == v.size()) {
            res += mid;
        }
        
    }
    //std::cout << res << "\n";
    if (r1 <= r) {
        ll mid = 1;
        std::vector<int> v;
        while (r1 > 0) {
            v.push_back(r1 % 10);
            r1 /= 10;
        }
        ll pow = 1;
        for (int i = 1; i < v.size() - 1; i++) {
            mid += (v[i] * pow);
            pow *= 10;
        }
        if (v[0] == v[v.size() - 1]) {
            res += mid;
        }
        
    } else {
        r1 -= 10;
        ll mid = 1;
        std::vector<int> v;
        while (r1 > 0) {
            v.push_back(r1 % 10);
            r1 /= 10;
        }
        ll pow = 1;
        for (int i = 1; i < v.size() - 1; i++) {
            mid += (v[i] * pow);
            pow *= 10;
        }
        if (v[0] == v[v.size() - 1] && num_r == v.size()) {
            res += mid;
        }
        
    }
    std::cout << res << "\n";
    return 0;
}