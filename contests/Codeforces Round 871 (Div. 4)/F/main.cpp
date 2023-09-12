#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e2 + 7;
int deg[MAXN];

int solve() {
    ///1 + x + x * y = n
    ///x + x * y = m
    ///x * y = cnt(vertexes with degree 1)
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        deg[i] = 0;
    }
    int x, y;
    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        --u, --v;
        deg[u]++;
        deg[v]++;
    }
    int one = 0;
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 1) {
            one++;
        }
    }
    x = m - one;
    y = one / x;
    cout << x << ' ' << y << '\n';
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
