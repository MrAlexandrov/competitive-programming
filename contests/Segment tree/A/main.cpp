#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 1e5 + 7;
const ll INF = INT_MAX;

class SegmentTree {
public:
    struct item {
        int l, r;
        ll sum, mn, mx;
        bool isupd, isadd;
        ll upd, add;
        item(ll val) :
            sum(val), mn(val), mx(val), isupd(false), isadd(false), upd(0), add(0) {}
        item() :
            sum(0), mn(INF), mx(-INF), isupd(false), isadd(false), upd(0), add(0) {}
    };

    ll n;
    vector <item> t;
    SegmentTree (ll n) : n(n) {
        t.resize(n);
        t[0].l = 0;
        t[0].r = n;
        buildLR(0);
    }
    SegmentTree (vector <ll> &a) {
        n = a.size();
        t.resize(n << 2);
        t[0].l = 0;
        t[0].r = n;
        buildLR(0);
        build(0, a);
    }
    item comb(const item &a, const item &b) {
        item res;
        res.sum = a.sum + b.sum;
        res.mn = min(a.mn, b.mn);
        res.mx = max(a.mx, b.mx);
        return res;
    }
    void buildLR(ll v) {
        if (t[v].r - t[v].l == 1) {
            return;
        }
        ll tm = (t[v].l + t[v].r) >> 1;
        t[2 * v + 1].l = t[v].l;
        t[2 * v + 1].r = tm;
        buildLR(2 * v + 1);
        t[2 * v + 2].l = tm;
        t[2 * v + 2].r = t[v].r;
        buildLR(2 * v + 2);
    }
    void build(ll v, const vector <ll> &a) {
        if (t[v].r - t[v].l == 1) {
            t[v] = item(a[ t[v].l ]);
            return;
        }
        build(2 * v + 1, a);
        build(2 * v + 2, a);
        t[v] = comb(t[2 * v + 1], t[2 * v + 2]);
    }
    void push(ll v) {
        if (t[v].isupd) {
            ll val = t[v].upd;

            t[v].sum = (t[v].r - t[v].l) * val; t[v].mn = val;
            t[v].isupd = false;

            if (!(t[v].r - t[v].l == 1)) {
                t[2 * v + 1].isupd = true; t[2 * v + 1].isadd = false;
                t[2 * v + 1].upd = val; t[2 * v + 1].add = 0;

                t[2 * v + 2].isupd = true; t[2 * v + 2].isadd = false;
                t[2 * v + 2].upd = val; t[2 * v + 2].add = 0;
            }
        }
        if (t[v].isadd) {
            ll val = t[v].add;

            t[v].sum += (t[v].r - t[v].l) * val; t[v].mn += val;
            t[v].isadd = false;
            t[v].add = 0;

            if (!(t[v].r - t[v].l == 1)) {
                t[2 * v + 1].isadd = true;
                t[2 * v + 1].add += val;

                t[2 * v + 2].isadd = true;
                t[2 * v + 2].add += val;
            }
        }
    }
    ll sum(ll v, ll l, ll r) {
        push(v);
        if (r <= t[v].l || t[v].r <= l) {
            return 0;
        }
        if (l <= t[v].l && t[v].r <= r) {
            return t[v].sum;
        }
        return sum(2 * v + 1, l, r) + sum(2 * v + 2, l, r);
    }
    ll sum(ll l, ll r) {
        return sum(0, l, r);
    }
    ll mn(ll v, ll l, ll r) {
        push(v);
        if (r <= t[v].l || t[v].r <= l) {
            return INF;
        }
        if (l <= t[v].l && t[v].r <= r) {
            return t[v].mn;
        }
        return min(mn(2 * v + 1, l, r), mn(2 * v + 2, l, r));
    }
    ll mn(ll l, ll r) {
        return mn(0, l, r);
    }
    void upd(ll v, ll l, ll r, ll val) {
        cout << v << ' ' << l << ' ' << r << ' ' << val << endl;
        push(v);
        if (r <= t[v].l || t[v].r <= l) {
            return;
        }
        if (l <= t[v].l && t[v].r <= r) {
            t[v].isupd = true; t[v].isadd = false;
            t[v].upd = val; t[v].add = 0;
            push(v);
            return;
        }
        upd(2 * v + 1, l, r, val);
        upd(2 * v + 2, l, r, val);
        t[v] = comb(t[2 * v + 1], t[2 * v + 2]);
    }
    void upd(ll l, ll r, ll val) {
        upd(0, l, r, val);
    }
    void add(ll v, ll l, ll r, ll val) {
        push(v);
        if (r <= t[v].l || t[v].r <= l) {
            return;
        }
        if (l <= t[v].l && t[v].r <= r) {
            t[v].isadd = true;
            t[v].add += val;
            push(v);
            return;
        }
        add(2 * v + 1, l, r, val);
        add(2 * v + 2, l, r, val);
        t[v] = comb(t[2 * v + 1], t[2 * v + 2]);
    }
    void add(ll l, ll r, ll val) {
        add(0, l, r, val);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    SegmentTree T(n);
    while (m--) {
        char c;
        int tl, tr, x;
        cout << "here -2" << endl;
        cin >> c;
        cout << "here -1" << endl;
        cin >> tl;
        cout << "here 0" << endl;
        cin >> tr;
        cout << "here 1" << endl;
        --tl;
        cout << "here 2" << endl;
        if (c == 'A') {
            cout << "here 3" << endl;
            cin >> x;
            T.upd(tl, tr, x);
        } else {
            cout << T.sum(tl, tr) << endl;
        }
    }
    return 0;
}

/**
5 9
A 2 3 2
A 3 5 1
A 4 5 2
Q 1 3
Q 2 2
Q 3 4
Q 4 5
Q 5 5
Q 1 5

**/
