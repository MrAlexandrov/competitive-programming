#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve() {
    ll res = 0;
    int n, a, x, m;
    cin >> n;
    cin >> a;
    cin >> x;
    cin >> m;
    ll water = 1LL * n * a;
    water -= x;
    res = water / m;
    res = max(0LL, res);
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int t = 1;
    //cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}

/**
3
6
5
2

---------------------
2 6 10 5

**/
