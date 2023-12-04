#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

mt19937_64 rnd(time(0));

const ll N = 1e6 + 7;
const ll M = 1e9 + 7;
//const ll P = 10;
//const ll P = 9901;
const ll P = 1e6 + 37;
int ABC = 26;

vector <ll> code;
vector <ll> power = {1LL};

ll sum(ll a, ll b) {
    return (a + b) % M;
}

ll mul(ll a, ll b) {
    return (a * b) % M;
}

ll sub(ll a, ll b) {
    return (a - b + M) % M;
}

ll binpow(ll a, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}

ll rev(ll a) {
    return binpow(a, M - 2);
}

ll myrnd(ll l, ll r) {
    return rnd() % (r - l) + l;
}

void start() {
    /*unordered_set <ll> s;
    while (s.size() < ABC) {
        s.insert(myrnd(1e2, 1e9 + 1));
    }
    for (auto i : s) {
        code.push_back(i);
    }*/
    for (int i = 1; i <= ABC; ++i) {
        code.push_back(i);
    }
    random_shuffle(code.begin(), code.end());
    for (ll i = 0; i < N; ++i) {
        power.push_back(mul(power.back(), P));
    }
}

void cnthash(const vector <int> &s, vector <int> &h) {
    int n = s.size();
    if (n == 0) {
        return;
    }
    h.resize(n);
    h[0] = code[s[0]];
    for (ll i = 1; i < n; ++i) {
        h[i] = mul(h[i - 1], P);
        h[i] = sum(h[i], code[s[i]]);
    }
}

ll cnthash(const vector <ll> &s) {
    ll res = 0;
    ll n = s.size();
    if (n == 0) {
        return -1;
    }
    for (ll i = 0; i < n; ++i) {
        res = sum(res, mul(code[s[i]], power[n - i - 1]));
    }
    return res;
}

int gethash(int l, int r, vector <int> &h) {
    if (l == r) {
        return 0;
    }
    if (l < 0) {
        return -1;
    }
    if (l == 0) {
        return h[r - 1];
    }
    return sub(h[r - 1], mul(h[l - 1], power[r - 1 - (l - 1)]));
}
///R
void cntRhash(const vector <int> &s, vector <int> &rh) {
    int n = s.size();
    if (n == 0) {
        return;
    }
    rh.resize(n);
    rh[0] = code[s[0]];
    for (int i = 1; i < n; ++i) {
        rh[i] = sum(rh[i - 1], mul(code[s[i]], power[i]));
    }
}

ll cntRhash(const vector <ll> &s) {
    ll res = 0;
    ll n = s.size();
    if (n == 0) {
        return -1;
    }
    for (ll i = 0; i < n; ++i) {
        res = sum(res, mul(code[s[i]], power[i]));
    }
    return res;
}

int getRhash(int l, int r, vector <int> &rh) {
    if (l == r) {
        return 0;
    }
    if (l < 0) {
        return -1;
    }
    if (l == 0) {
        return rh[r - 1];
    }
    return mul(sub(rh[r - 1], rh[l - 1]), rev(power[l]));
}

vector <int> manacher_even(const vector <int> &s) {
    int n = (int) s.size();
    vector <int> d(n, 0);
    int l = -1, r = -1;
    for (int i = 0; i < n - 1; i++) {
        if (i < r)
            d[i] = min(r - i, d[l + r - i - 1]);
        while (i - d[i] >= 0 && i + d[i] + 1 < n && s[i - d[i]] == s[i + d[i] + 1])
            ++d[i];
        if (i + d[i] > r)
            l = i - d[i] + 1, r = i + d[i];
    }
    return d;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int n;
    cin >> n >> ABC;
    ++ABC;
    vector <int> a(n);
    for (int &i : a) {
        cin >> i;
    }
    vector <int> d1 = manacher_even(a);
    start();
    vector <int> hs, Rhs;
    cnthash(a, hs);
    cntRhash(a, Rhs);
    for (int i = 0; i < n; ++i) {
        if (d1[i] + (i + 1) == n) {
            cout << i + 1 << ' ';
        }
    }
    return 0;
}

/**
6 2
1 1 2 2 1 1

**/
