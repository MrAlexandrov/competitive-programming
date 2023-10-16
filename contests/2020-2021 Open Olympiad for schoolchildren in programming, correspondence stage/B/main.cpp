#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> a[m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << (j < n ? (j + i) % n + 1 : 0) << ' ';
        }
        cout << '\n';
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/**
3 1 1

-----------------
4 2 2

----------------
5 3 2

**/
