#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, q;
    cin >> n >> q;
    vector <int> a(q);
    for (int &i : a) {
        cin >> i;
    }
    for (int i = 0; i < n - 2; ++i) {
        cout << i + 1 << ' ' << i + 2 << '\n';
    }
    cout << n << ' ' << a[0] << '\n';
    int prev = a[0];
    cout << "-1 -1 -1\n";
    for (int i = 1; i < q; ++i) {
        if (a[i] == a[i - 1]) {
            cout << "-1 -1 -1\n";
        } else {
            cout << n << ' ' << prev << ' ' << a[i] << '\n';
            prev = a[i];
        }
    }
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
1 - 2 - 3 - 4 - ... - n - 1
        |
        n

**/
