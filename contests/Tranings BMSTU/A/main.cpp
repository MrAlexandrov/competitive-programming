#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int n, X;
    cin >> n >> X;
    vector <int> a(n);
    ll ans = 0;
    map <int, ll> ost;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i) {
            a[i] += a[i - 1];
        }
        a[i] %= X;
        ost[a[i]]++;
    }
    ost[0]++;
    for (auto [mod, cnt] : ost) {
        ans += cnt * (cnt - 1) / 2;
    }
    cout << ans;
    return 0;
}

/**


**/
