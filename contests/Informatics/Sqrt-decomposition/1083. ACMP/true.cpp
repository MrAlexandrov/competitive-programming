#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const ll N = 1e3 + 8;
const ll INF = INT_MAX;
 
ll n, m;
vector <ll> a(N);
 
struct item {
    ll sum, mn;
    bool isupd, isadd;
    ll upd, add;
    item (ll val) {
        sum = mn = val;
        isupd = isadd = false;
        upd = add = 0;
    }
    item () {
        sum = 0; mn = INF;
        isupd = isadd = false;
        upd = add = 0;
    }
};
 
vector <item> t(N << 2);
 
item comb(const item &a, const item &b) {
    item res;
    res.sum = a.sum + b.sum;
    res.mn = min(a.mn, b.mn);
    return res;
}
 
void build(ll v, ll tl, ll tr) {
    if (tr - tl == 1) {
        t[v] = item(a[tl]);
        return;
    }
    ll tm = (tl + tr) >> 1;
    build(2 * v + 1, tl, tm);
    build(2 * v + 2, tm, tr);
    t[v] = comb(t[2 * v + 1], t[2 * v + 2]);
}
 
void push(ll v, ll tl, ll tr) {
    if (t[v].isupd) {
        ll val = t[v].upd;
 
        t[v].sum = (tr - tl) * val; t[v].mn = val;
        t[v].isupd = false;
 
        if (!(tr - tl == 1)) {
            t[2 * v + 1].isupd = true; t[2 * v + 1].isadd = false;
            t[2 * v + 1].upd = val; t[2 * v + 1].add = 0;
 
            t[2 * v + 2].isupd = true; t[2 * v + 2].isadd = false;
            t[2 * v + 2].upd = val; t[2 * v + 2].add = 0;
        }
    }
    if (t[v].isadd) {
        ll val = t[v].add;
 
        t[v].sum += (tr - tl) * val; t[v].mn += val;
        t[v].isadd = false;
        t[v].add = 0;
 
        if (!(tr - tl == 1)) {
            t[2 * v + 1].isadd = true;
            t[2 * v + 1].add += val;
 
            t[2 * v + 2].isadd = true;
            t[2 * v + 2].add += val;
        }
    }
}
 
ll sum(ll v, ll tl, ll tr, ll l, ll r) {
    push(v, tl, tr);
    if (r <= tl || tr <= l) {
        return 0;
    }
    if (l <= tl && tr <= r) {
        return t[v].sum;
    }
    ll tm = (tl + tr) >> 1;
    return sum(2 * v + 1, tl, tm, l, r) + sum(2 * v + 2, tm, tr, l, r);
}
 
ll mn(ll v, ll tl, ll tr, ll l, ll r) {
    push(v, tl, tr);
    if (r <= tl || tr <= l) {
        return INF;
    }
    if (l <= tl && tr <= r) {
        return t[v].mn;
    }
    ll tm = (tl + tr) >> 1;
    return min(mn(2 * v + 1, tl, tm, l, r), mn(2 * v + 2, tm, tr, l, r));
}
 
void upd(ll v, ll tl, ll tr, ll l, ll r, ll val) {
    push(v, tl, tr);
    if (r <= tl || tr <= l) {
        return;
    }
    if (l <= tl && tr <= r) {
        t[v].isupd = true; t[v].isadd = false;
        t[v].upd = val; t[v].add = 0;
        push(v, tl, tr);
        return;
    }
    ll tm = (tl + tr) >> 1;
    upd(2 * v + 1, tl, tm, l, r, val);
    upd(2 * v + 2, tm, tr, l, r, val);
    t[v] = comb(t[2 * v + 1], t[2 * v + 2]);
}
 
void add(ll v, ll tl, ll tr, ll l, ll r, ll val) {
    push(v, tl, tr);
    if (r <= tl || tr <= l) {
        return;
    }
    if (l <= tl && tr <= r) {
        t[v].isadd = true;
        t[v].add += val;
        push(v, tl, tr);
        return;
    }
    ll tm = (tl + tr) >> 1;
    add(2 * v + 1, tl, tm, l, r, val);
    add(2 * v + 2, tm, tr, l, r, val);
    t[v] = comb(t[2 * v + 1], t[2 * v + 2]);
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    build(0, 0, n);
    cin >> m;
    for (ll i = 0; i < m; ++i) {
        string s;
        cin >> s;
        if (s == "rsq") {
            ll l, r;
            cin >> l >> r;
            --l;
            cout << sum(0, 0, n, l, r) << endl;
        } else if (s == "update") {
            ll l, r, val;
            cin >> l >> r >> val;
            --l;
            upd(0, 0, n, l, r, val);
        } else if (s == "rmq") {
            ll l, r;
            cin >> l >> r;
            --l;
            cout << mn(0, 0, n, l, r) << endl;
        } else if (s == "add") {
            ll l, r, val;
            cin >> l >> r >> val;
            --l;
            add(0, 0, n, l, r, val);
        } else if (s == "get") {
            ll x;
            cin >> x;
            cout << sum(0, 0, n, x - 1, x) << endl;
        }
    }
    return 0;
}
 
/**
 
 
**/