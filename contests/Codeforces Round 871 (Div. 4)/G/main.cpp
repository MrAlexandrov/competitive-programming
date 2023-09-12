#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2023 + 7;

ll sqrt(ll n) {
    int l = 0, r = 1001;
    while (r - l > 1) {
        int m = l + r >> 1;
        if (m * m < n) {
            l = m;
        } else {
            r = m;
        }
    }
    return r;
}

ll table[MAXN][MAXN];
ll ans[MAXN][MAXN];

ll solve() {
    ll res = 0;
    int n;
    cin >> n;
    //n = sqrt(n);
    int i = 1, j = 0;
    while (n > 0) {
        if (n > i) {
            n -= i;
            i++;
        } else {
            j = n;
            n -= j;
        }
    }
    i--;
    j--;
    //cout << i << ' ' << j << '\n';
    res = ans[i][j];
    return res;
}

bool check(int i, int j) {
    return (i >= 0 && j >= 0 && i >= j);
}

ll add(int i, int j) {
    if (check(i, j)) {
        return ans[i][j];
    } else {
        return 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int cnt = 1;
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j <= i; ++j) {
            table[i][j] = cnt++;
            ans[i][j] = table[i][j] * table[i][j];
        }
    }
    /*
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << table[i][j] << '\t';
        }
        cout << '\n';
    }
    cout << "-----------\n";
    */
    for (int i = 0; i < MAXN - 1; ++i) {
        for (int j = 0; j <= i; ++j) {
            ans[i][j] += add(i - 1, j - 1);
            ans[i][j] += add(i - 1, j);
            ans[i][j] -= add(i - 2, j - 1);
        }
    }
    /*
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << ans[i][j] << '\t';
        }
        cout << '\n';
    }
    return 0;
    */
    int t = 1;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}

/**


**/
