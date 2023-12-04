#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n, m;
    cin >> m >> n;
    vector <ll> a;
    vector <ll> pref;
    a.push_back(0);
    pref.push_back(0);
    ll x;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (x > 0) {
            a.push_back(x);
            pref.push_back(pref.back() + x);
        }
    }
    n = a.size() - 1;
    ll res = 0;
    int l, r;
    for (l = n; l > 0; --l) {
        r = min(n, l + a[l]);
        res += pref[r] - pref[l];
        res += a[l] * a[l];
    }
    cout << res;
    return 0;
}

/**


**/
