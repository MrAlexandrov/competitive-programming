#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector <ll> a(n);
    for (ll &i : a) {
        cin >> i;
    }
    vector <ll> move_left(n), move_right(n);
    ll l = 0, r = 1e16;
    while (r - l > 1) {
        ///cout << l << ' ' << r << endl;
        ll m = (r - l) / 2;
        m += l;
        bool ok = true;
        int ind_bad = -1;
        int more_eq = 0;
        int less_eq = n - 1;
        for (int i = 0; i < n; ++i) {
            if (m < a[i]) {
                ok = false;
                break;
            }
            move_left[i] = m - i;
            move_right[i] = m - (n - (i + 1));
            ///cout << "move " << move_left[i] << ' ' << move_right[i] << endl;
            if (move_left[i] < a[i]) {
                more_eq = max(more_eq, i);
            }
            if (move_right[i] < a[i]) {
                less_eq = min(less_eq, i);
            }
        }
        if (less_eq < more_eq) {
            ok = false;
        }
        if (ok) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int t = 1;
    ///cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/**


**/
