#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int x = 0;
    int n, k;
    cin >> n >> k;
    int i = 0;
    int now;
    while (i + k <= n) {
        cout << "? " << i + 1 << endl;
        i += k;
        cin >> now;
        x ^= now;
    }
    int half = (n - i) / 2;
    while (i < n) {
        cout << "? " << i - k + half + 1 << endl;
        i += half;
        cin >> now;
        x ^= now;
    }
    cout << "! " << x << endl;
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
0 1 2 3 4 5 6 7
3 4 4 7 3 6 2 7

**/
