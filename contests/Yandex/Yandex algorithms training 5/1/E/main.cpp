#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int n, k, d;
    cin >> n >> k >> d;
    long long ans = n;
    for (long long i = n * 10; i < n * 10 + 10; ++i) {
        if (i % k == 0) {
            ans = i;
            break;
        }
    }
    if (ans == n) {
        cout << -1;
    } else {
        cout << ans;
        for (int i = 0; i < d - 1; ++i) {
            cout << 0;
        }
    }
    return 0;
}

/**
(n * 10 + c1) % k == 0                  : 10 * n + c1            = k * d1
((n * 10 + c1) * 10 + c2) % k == 0      : 100 * n + 10 * c1 + c2 = k * d2

29420920 98069736 69929

**/

