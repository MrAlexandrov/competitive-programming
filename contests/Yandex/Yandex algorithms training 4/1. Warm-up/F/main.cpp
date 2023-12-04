#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    ll k;
    cin >> k;
    ll n;
    cin >> n;
    vector <ull> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ull ans = 0;
    ull dop = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (dop >= a[i]) {
            dop -= a[i];
            a[i] = 0;
            continue;
        }
        a[i] -= dop;
        dop = 0;
        ull p = a[i] / k;
        dop = k - (a[i] % k);
        if (dop == k) dop = 0;
        if (dop > 0) ++p;
        ans += 1ULL * (i + 1) * p;
    }
    ans <<= 1;
    cout << ans;
    return 0;
}

/**


**/
