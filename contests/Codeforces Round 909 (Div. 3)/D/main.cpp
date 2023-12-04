#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    map <int, int> m;
    for (int &i : a) {
        cin >> i;
        ++m[i];
    }
    ll ans = 0;
    for (auto [num, cnt] : m) {
        ans += (ll)cnt * (cnt - 1) / 2;
    }
    ans += (ll)m[1] * m[2];
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/**
(2 ^ x) ^ (2 ^ y) == (2 ^ y) ^ (2 ^ x)
2 ^ (x * (2 ^ y) == 2 ^ (y * (2 ^ x))
x * (2 ^ y) == y * (2 ^ x)
x < y
x * 2 ^ (y - x) == y
2 ^ (y - x) == y / x

(2 ^ 1) ^ (2 ^ 2) == (2 ^ 2) ^ (2 ^ 1)
2 ^ (2 - 1) == 2 / 1
2 == 2


**/
