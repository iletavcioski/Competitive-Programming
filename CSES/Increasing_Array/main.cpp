#include <iostream>
#include <vector>

int N;
std::vector<int> array;

void read() {
    std::cin >> N;
    array.resize(N);
    for (int i = 0; i < N; i++) {
        std::cin >> array[i];
    }
}

void solve(int &n, std::vector<int> &arr) {
    long long cnt = 0;
    for (int i = 1; i < n; i++) {
        cnt += std::max(arr[i - 1] - arr[i], 0);
        if (arr[i] < arr[i - 1])
            arr[i] = arr[i - 1];
    }
    std::cout << cnt << std::endl;
}

int main() {
    read();
    solve(N, array);
    return 0;
}
