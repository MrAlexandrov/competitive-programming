#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector <ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        a[i] += a[i - 1];
    }
    ll ans = 0;
    for (int k = 1; k <= n; ++k) {
        if (n % k != 0) continue;
        ll mx = -1;
        ll mn = (ll)1e15;
        for (int i = k; i <= n; i += k) {
            ll now = a[i] - a[i - k];
            mx = max(mx, now);
            mn = min(mn, now);
        }
        ans = max(ans, mx - mn);
    }
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


**/
