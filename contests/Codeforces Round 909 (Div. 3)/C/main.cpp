#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e9;

int fnd(vector <int> &a, int l, int r) {
    int best = -INF, sum = 0;
    for (int i = l; i < r; ++i) {
        sum = max(a[i], sum + a[i]);
        best = max(best, sum);
    }
    return best;
}

void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    int ans = -INF;
    for (int &i : a) {
        cin >> i;
        ans = max(ans, i);
    }
    int prev = 0;
    for (int i = 0; i < n - 1; ++i) {
        if ((a[i] + a[i + 1] + INF) % 2 == 0) {
            ans = max(ans, fnd(a, prev, i + 1));
            ///cout << prev << ' ' << i + 1 << endl;
            prev = i + 1;
        }
    }
    ans = max(ans, fnd(a, prev, n));
    cout << ans << '\n';
    ///cout << endl;
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
