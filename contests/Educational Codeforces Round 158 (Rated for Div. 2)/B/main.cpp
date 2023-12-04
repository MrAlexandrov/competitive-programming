#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector <int> c(n + 1);
    c[0] = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (c[i - 1] < c[i]) {
            ans += c[i] - c[i - 1];
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    /*freopen("input.txt", "w", stdout);
    cout << "1\n";
    int n = 2e5;
    cout << n << '\n';
    for (int i = 0; i < n; ++i) {
        if (i & 1) {
            cout << "1000000000 ";
        } else {
            cout << "1 ";
        }
    }
    return 0;*/
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/**
1
2
1 2

**/
