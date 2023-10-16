#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e6 + 7;
const int N = 2e5 + 7;

int n, b;
vector <int> a(N);
vector <ll> d(N, 0);            /// maximum length, if end in d[i]

struct item {
    ll mx;
    item(ll val) {
        mx = val;
    }
    item() {
        mx = -INF;
    }
};

item neutral;

struct ST {
    ll n;
    vector <item> t;
    ST (const vector <ll> &a) {
        n = a.size();
        t.resize(n << 2);
        build(0, 0, n, a);
    }
    item comb(const item &a, const item &b) {
        item res;
        res.mx = max(a.mx, b.mx);
        return res;
    }
    void build(ll v, ll tl, ll tr, const vector <ll> &a) {
        if (tr - tl == 1) {
            t[v] = item(a[tl]);
            return;
        }
        ll tm = (tl + tr) >> 1;
        build(2 * v + 1, tl, tm, a);
        build(2 * v + 2, tm, tr, a);
        t[v] = comb(t[2 * v + 1], t[2 * v + 2]);
    }
    ll mx(ll v, ll tl, ll tr, ll l, ll r) {
        if (r <= tl || tr <= l) {
            return neutral.mx;
        }
        if (l <= tl && tr <= r) {
            return t[v].mx;
        }
        ll tm = (tl + tr) >> 1;
        return max(mx(2 * v + 1, tl, tm, l, r), mx(2 * v + 2, tm, tr, l, r));
    }
    ll mx(ll l, ll r) {
        return mx(0, 0, n, l, r + 1);
    }
    ll mx(ll x) {
        return mx(0, 0, n, x, x + 1);
    }
    void upd(ll v, ll tl, ll tr, ll l, ll r, ll val) {
        if (r <= tl || tr <= l) {
            return;
        }
        if (l <= tl && tr <= r) {
            t[v].mx = val;
            return;
        }
        ll tm = (tl + tr) >> 1;
        upd(2 * v + 1, tl, tm, l, r, val);
        upd(2 * v + 2, tm, tr, l, r, val);
        t[v] = comb(t[2 * v + 1], t[2 * v + 2]);
    }
    void upd(ll x, ll val) {
        upd(0, 0, n, x, x + 1, val);
    }
};


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n >> b;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ST tree(d);
    for (int i = 0; i < n; ++i) {
        int l = a[i] - b, r = a[i];
        int mx = tree.mx(l, r);
        if (d[a[i]] < mx + 1) {
            d[a[i]] = mx + 1;
            tree.upd(a[i], mx + 1);
        }
    }
    cout << tree.mx(0, n) << endl;
    return 0;
}

/**
6 6
5 3 2 4 6 1

7 1
0 1 2 3 4 5 6

10 3
10 5 4 2 2 0 7 1 10 7

10 0
1 5 3 5 9 2 3 3 9 8

8 3
3 4 0 7 8 8 3 3

**/
