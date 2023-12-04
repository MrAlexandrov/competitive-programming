#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 1e5 + 7;
const ll INF = 2e9 + 7;

struct sqrt_decomposition {
    ll n;
    const ll K = 315;
    vector <ll> a;
    vector <ll> sz;
    vector <ll> sum;
    vector <ll> mn;
    vector <bool> is_upd;
    vector <ll> upd;
    vector <bool> is_add;
    vector <ll> add;
    ll cnt_blocks = 0;
    sqrt_decomposition(vector <ll> &_a) : n(_a.size()) {
        a = _a;
        cnt_blocks = (n + K - 1) / K;
        sz.resize(n / K + 7);
        sum.resize(n / K + 7, 0);
        mn.resize(n / K + 7, INF);
        is_upd.resize(n / K + 7, false);
        upd.resize(n / K + 7, 0);
        is_add.resize(n / K + 7, false);
        add.resize(n / K + 7, 0);
        build(a);
    }
    void build(const vector <ll> &a) {
        for (ll l = 0; l < n; l += K) {
            ll block = l / K;
            ll current_size = 0;
            for (ll i = l; i < l + K && i < n; ++i, ++current_size) {
                sum[block] += a[i];
                mn[block] = min(mn[block], a[i]);
            }
            sz[block] = current_size;
        }
    }
    void push(ll block) {
        if (is_upd[block]) {
            for (ll i = block * K; i < block * K + sz[block]; ++i) {
                a[i] = upd[block];
            }
            //sum[block] = upd[block] * sz[block];
            //mn[block] = upd[block];
            is_upd[block] = false;
            upd[block] = 0;
        }
        if (is_add[block]) {
            for (ll i = block * K; i < block * K + sz[block]; ++i) {
                a[i] += add[block];
            }
            //sum[block] += add[block] * sz[block];
            //mn[block] += add[block];
            is_add[block] = false;
            add[block] = false;
        }
    }
    void recalc(ll block) {
        push(block);
        sum[block] = 0;
        mn[block] = INF;
        for (ll i = block * K; i < block * K + sz[block]; ++i) {
            sum[block] += a[i];
            mn[block] = min(mn[block], a[i]);
        }
    }
    ll get_sum(ll l, ll r) {
        ll res = 0;
        while (l < r) {
            ll block = l / K;
            if (l % K == 0 && l + sz[block] <= r) {
                res += sum[block];
                l += sz[block];
            } else {
                ll cur = 0;
                ll cur_r = min(block * K + sz[block], r);
                if (is_upd[block]) {
                    cur = upd[block] * (cur_r - l);
                } else {
                    for (ll i = l; i < cur_r; ++i) {
                        cur += a[i];
                    }
                }
                if (is_add[block]) {
                    cur += add[block] * (cur_r - l);
                }
                res += cur;
                l = cur_r;
            }
        }
        return res;
    }
    ll get_min(ll l, ll r) {
        ll res = INF;
        while (l < r) {
            ll block = l / K;
            if (l % K == 0 && l + sz[block] <= r) {
                res = min(res, mn[block]);
                l += sz[block];
            } else {
                ll cur = INF;
                ll cur_r = min(block * K + sz[block], r);
                if (is_upd[block]) {
                    cur = upd[block];
                } else {
                    for (ll i = l; i < cur_r; ++i) {
                        cur = min(cur, a[i]);
                    }
                }
                if (is_add[block]) {
                    cur += add[block];
                }
                res = min(res, cur);
                l = cur_r;
            }
        }
        return res;
    }
    ll get(ll l) {
        ll block = l / K;
        ll res = (is_upd[block] ? upd[block] : a[l]);
        res += (is_add[block] ? add[block] : 0);
        return res;
    }
    void update(ll l, ll r, ll x) {
        while (l < r) {
            ll block = l / K;
            ///push(block);
            if (l % K == 0 && l + sz[block] <= r) {
                    is_upd[block] = true;
                    is_add[block] = false;
                    add[block] = 0;
                    upd[block] = x;
                    sum[block] = x * sz[block];
                    mn[block] = x;
                    l += sz[block];
            } else {
                push(block);
                for (; l < block * K + sz[block] && l < r; ++l) {
                    a[l] = x;
                }
                recalc(block);
            }
        }
    }
    void add_el(ll l, ll r, ll x) {
        while (l < r) {
            ll block = l / K;
            ///push(block);
            if (l % K == 0 && l + sz[block] <= r) {
                is_add[block] = true;
                add[block] += x;
                sum[block] += x * sz[block];
                mn[block] += x;
                l += sz[block];
            } else {
                push(block);
                for (; l < block * K + sz[block] && l < r; ++l) {
                    a[l] += x;
                }
                recalc(block);
            }
        }
    }
    void viv() {
        cout << '\n';
        cout << "array:\t";
        for (ll i = 0; i < n; ++i) {
            cout << a[i] << ' ';
        }
        cout << '\n';
        cout << "sz:\t";
        for (ll i = 0; i < cnt_blocks; ++i) {
            cout << sz[i] << ' ';
        }
        cout << '\n';
        cout << "sum:\t";
        for (ll i = 0; i < cnt_blocks; ++i) {
            cout << sum[i] << ' ';
        }
        cout << '\n';
        cout << "min:\t";
        for (ll i = 0; i < cnt_blocks; ++i) {
            cout << mn[i] << ' ';
        }
        cout << '\n';
        cout << "is_upd:\t";
        for (ll i = 0; i < cnt_blocks; ++i) {
            cout << is_upd[i] << ' ';
        }
        cout << '\n';
        cout << "upd:\t";
        for (ll i = 0; i < cnt_blocks; ++i) {
            cout << upd[i] << ' ';
        }
        cout << '\n';
        cout << "is_add:\t";
        for (ll i = 0; i < cnt_blocks; ++i) {
            cout << is_add[i] << ' ';
        }
        cout << '\n';
        cout << "add:\t";
        for (ll i = 0; i < cnt_blocks; ++i) {
            cout << add[i] << ' ';
        }
        cout << '\n';
        cout << "real:\t";
        for (ll i = 0; i < n; i += K) {
            ll block = i / K;
            for (ll l = i; l < i + K && l < n; ++l) {
                ll cur = (is_upd[block] ? upd[block] : a[l]);
                cur += (is_add[block] ? add[block] : a[l]);
                cout << cur << ' ';
            }
        }
        cout << '\n' << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    ll n;
    cin >> n;
    vector <ll> a(n);
    for (ll &i : a) {
        cin >> i;
    }
    sqrt_decomposition SQD(a);
    ll m;
    cin >> m;
    for (ll i = 0; i < m; ++i) {
        string s;
        cin >> s;
        ll l, r, x;
        if (s == "rsq") {
            cin >> l >> r;
            cout << SQD.get_sum(l - 1, r) << '\n';
        } else if (s == "update") {
            cin >> l >> r >> x;
            SQD.update(l - 1, r, x);
        } else if (s == "rmq") {
            cin >> l >> r;
            cout << SQD.get_min(l - 1, r) << '\n';
        } else if (s == "add") {
            cin >> l >> r >> x;
            SQD.add_el(l - 1, r, x);
        } else if (s == "get") {
            cin >> l;
            cout << SQD.get(l - 1) << '\n';
        }
        ///SQD.viv();
    }
    return 0;
}

/**
10
1 2 3 4 5 6 7 8 9 10
5
rsq 1 10
update 5 6 2
rmq 3 9
add 2 8 3
get 7

-------------------
12
3 15 1 15 12 19 25 27 13 9 10 24
19
get 1
rmq 7 7
rmq 6 7
rsq 8 11
update 5 8 14
update 1 11 19
add 4 8 4
rsq 9 10
rsq 3 10
rmq 5 12
rmq 9 10
get 5
add 1 4 25
add 2 6 21
rsq 4 11
add 4 5 22
update 3 4 16
add 3 10 22
rsq 4 12

------------------------------
12
3 15 1 15 12 19 25 27 13 9 10 24
19
get 1
[3] 15 1 15 12 19 25 27 13 9 10 24
rmq 7 7
3 15 1 15 12 19 [25] 27 13 9 10 24
rmq 6 7
3 15 1 15 12 [19 25] 27 13 9 10 24
rsq 8 11
3 15 1 15 12 19 25 [27 13 9 10] 24
update 5 8 14
3 15 1 15 [12 19 25 27] 13 9 10 24
3 15 1 15 [14 14 14 14] 13 9 10 24
update 1 11 19
[3 15 1 15 14 14 14 14 13 9 10] 24
19 19 19 19 19 19 19 19 19 19 19 24
add 4 8 4
19 19 19 [19 19 19 19 19] 19 19 19 24
19 19 19 23 23 23 23 23 19 19 19 24
rsq 9 10
19 19 19 23 23 23 23 23 [19 19] 19 24
rsq 3 10
19 19 [19 23 23 23 23 23 19 19] 19 24
rmq 5 12
19 19 19 23 [23 23 23 23 19 19 19 24]
rmq 9 10
get 5
add 1 4 25
add 2 6 21
rsq 4 11
add 4 5 22
update 3 4 16
add 3 10 22
rsq 4 12

**/
