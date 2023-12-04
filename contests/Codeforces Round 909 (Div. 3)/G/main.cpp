#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 7;
vector <int> g[N];
int timer;
int tin[N]{};
int tout[N]{};

struct ST {
    int n;
    vector <vector <int>> t;
    ST (vector <int> &a) : n(a.size()) {
        t.resize(n << 2);
        build(0, 0, n, a);
    }
    vector <int> comb(const vector <int> &a, const vector <int> &b) {
        int n = a.size(), m = b.size();
        vector <int> res(n + m);
        int it1 = 0, it2 = 0;
        while (it1 < n && it2 < m) {
            if (a[it1] < b[it2]) {
                res[it1 + it2] = a[it1];
                ++it1;
            } else {
                res[it1 + it2] = b[it2];
                ++it2;
             }
        }
        while (it1 < n) {
            res[it1 + it2] = a[it1];
            ++it1;
        }
        while (it2 < m) {
            res[it1 + it2] = b[it2];
            ++it2;
        }
        return res;
    }
    void build(int v, int tl, int tr, const vector <int> &a) {
        if (tr - tl == 1) {
            t[v] = {a[tl]};
            return;
        }
        int tm = (tl + tr) >> 1;
        build(2 * v + 1, tl, tm, a);
        build(2 * v + 2, tm, tr, a);
        t[v] = comb(t[2 * v + 1], t[2 * v + 2]);
    }
    int cnt(int v, int tl, int tr, int l, int r, int mn, int mx) {
        if (r <= tl || tr <= l) {
            return 0;
        }
        if (l <= tl && tr <= r) {
            return lower_bound(t[v].begin(), t[v].end(), mx) - lower_bound(t[v].begin(), t[v].end(), mn);
        }
        int tm = (tl + tr) >> 1;
        return cnt(2 * v + 1, tl, tm, l, r, mn, mx) + cnt(2 * v + 2, tm, tr, l, r, mn, mx);
    }
    int cnt(int l, int r, int mn, int mx) {
        return cnt(0, 0, n, l, r, mn, mx);
    }
};

void DFS(int v, int from) {
    tin[v] = timer++;
    for (int to : g[v]) {
        if (to == from) continue;
        DFS(to, v);
    }
    tout[v] = timer;
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    timer = 0;
    DFS(0, -1);
    for (int i = 0; i < n; ++i) {
        g[i].clear();
    }

    vector <int> p(n);
    for (int &i : p) {
        cin >> i;
        --i;
    }
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = tin[p[i]];
    }
    ST tree(a);


    for (int i = 0; i < q; ++i) {
        int l, r, x;
        cin >> l >> r >> x;
        --l, --x;
        cout << (tree.cnt(l, r, tin[x], tout[x]) ? "YES" : "NO") << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}

/**


**/
