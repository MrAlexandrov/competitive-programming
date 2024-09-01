#include <bits/stdc++.h>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        
        long long a = 0, b = 1'000'000'000;
        while (b - a > 1) {
            long long mid = (a + b) >> 1;
            long long sum = mid * (mid + 1) / 2;
            if (l + sum <= r) {
                a = mid;
            } else {
                b = mid;
            }
        }
        cout << b << endl;
        // for (int i = l, add = 1; i <= r; i += add, add += 1) {
        //     cout << i << endl;
        // }
    }
    return 0;
}

/**

1 + 2 + 3 + 4 + ... + n

**/