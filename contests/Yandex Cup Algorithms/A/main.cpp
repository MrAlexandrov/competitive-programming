#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef pair <long long, long long> pll;

const ll N = 1e5 + 8;
const ll INF = INT_MAX;

ll n, m;

struct item {
    ll mn;
    ll pos;
    item(ll val, ll _pos) {
        mn = val;
        pos = _pos;
    }
    item() {
        mn = INF;
        pos = -1;
    }
};

item zero;

struct ST {
    ll n;
    vector <item> t;
    ST (vector <ll> &a) {
        n = a.size();
        t.resize(n << 2);
        build(0, 0, n, a);
    }
    item comb(const item &a, const item &b) {
        item res;
        if (a.mn == b.mn) {
            res.mn = a.mn;
            res.pos = max(a.pos, b.pos);
        } else {
            res = (a.mn < b.mn ? a : b);
        }
        return res;
    }
    void build(ll v, ll tl, ll tr, const vector <ll> &a) {
        if (tr - tl == 1) {
            t[v] = item(a[tl], tl);
            return;
        }
        ll tm = (tl + tr) >> 1;
        build(2 * v + 1, tl, tm, a);
        build(2 * v + 2, tm, tr, a);
        t[v] = comb(t[2 * v + 1], t[2 * v + 2]);
    }
    item mn(ll v, ll tl, ll tr, ll l, ll r) {
        if (r <= tl || tr <= l) {
            return zero;
        }
        if (l <= tl && tr <= r) {
            return t[v];
        }
        ll tm = (tl + tr) >> 1;
        return comb(mn(2 * v + 1, tl, tm, l, r), mn(2 * v + 2, tm, tr, l, r));
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    vector <ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ST T(a);
    int now = 0;
    int ans = 0;
    int prev = 0;
    while (now < n) {
        item temp = T.mn(0, 0, n, now, n);
        if (prev + 1 == temp.mn) {
            prev = temp.mn;
            ++ans;
        } else {
            break;
        }
        now = temp.pos + 1;
    }
    cout << ans;
    return 0;
}

/**


**/
