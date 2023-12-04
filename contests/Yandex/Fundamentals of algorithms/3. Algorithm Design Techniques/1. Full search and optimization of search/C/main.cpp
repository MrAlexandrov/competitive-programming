#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int fact(int n) {
    int res = 1;
    for (int i = 2; i <= n; ++i) {
        res *= i;
    }
    return res;
}

int C(int n, int k) {
    return fact(n) / (fact(k) * fact(n - k));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    cout << C(n + k - 1, k);
    return 0;
}

/**


**/
