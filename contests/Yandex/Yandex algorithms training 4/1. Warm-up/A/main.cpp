#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 7;

int mn[N][18], mx[N][18], a[N];
void build(int n) {
    for (int i = 1; i <= n; ++i) mn[i][0] = a[i];
    for (int i = 1; i <= n; ++i) mx[i][0] = a[i];
    for (int k = 1; k < 18; ++k) {
        for (int i = 1; i + (1 << k) - 1 <= n; ++i) {
            mn[i][k] = min(mn[i][k - 1], mn[i + (1 << (k - 1))][k - 1]);
            mx[i][k] = max(mx[i][k - 1], mx[i + (1 << (k - 1))][k - 1]);
        }
    }
}

int query_min(int l, int r) {
    int k = 31 - __builtin_clz(r - l + 1);
    return min(mn[l][k], mn[r - (1 << k) + 1][k]);
}

int query_max(int l, int r) {
    int k = 31 - __builtin_clz(r - l + 1);
    return max(mx[l][k], mx[r - (1 << k) + 1][k]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    build(n);
    int l, r;
    while (m--) {
        cin >> l >> r;
        ++l, ++r;
        int q_min = query_min(l, r);
        int q_max = query_max(l, r);
        if (q_min == q_max) {
            cout << "NOT FOUND\n";
        } else {
            cout << q_max << '\n';
        }
    }
    return 0;
}

/**


**/
