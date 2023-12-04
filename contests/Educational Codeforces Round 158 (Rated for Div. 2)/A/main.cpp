#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, x;
    cin >> n >> x;
    vector <int> a(n + 2);
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    a[n + 1] = x;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, a[i + 1] - a[i]);
    }
    ans = max(ans, 2 * (a[n + 1] - a[n]));
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/**
1
3 21
10 15 20

**/
