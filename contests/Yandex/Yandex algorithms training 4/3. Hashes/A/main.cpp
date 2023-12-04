#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

mt19937_64 rnd(time(0));

const ll N = 2e5 + 7;
const ll M = 1e9 + 7;
const ll P = 9901;
const ll ABC = 26;

vector <ll> code;
vector <ll> power = {1LL};

string s;

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
    unordered_set <ll> s;
    while (s.size() < ABC) {
        s.insert(myrnd(1e3, 1e4 + 1));
    }
    for (auto i : s) {
        code.push_back(i);
    }
    for (ll i = 0; i < N; ++i) {
        power.push_back(mul(power.back(), P));
    }
}

void cnthash(const string &s, vector <ll> &h) {
    ll n = s.size();
    if (n == 0) {
        return;
    }
    h.resize(n);
    h[0] = code[s[0] - 'a'];
    for (ll i = 1; i < n; ++i) {
        h[i] = mul(h[i - 1], P);
        h[i] = sum(h[i], code[s[i] - 'a']);
    }
}

ll cnthash(const string &s) {
    ll res = 0;
    ll n = s.size();
    if (n == 0) {
        return -1;
    }
    for (ll i = 0; i < n; ++i) {
        res = sum(res, mul(code[s[i] - 'a'], power[n - i - 1]));
    }
    return res;
}

ll gethash(ll l, ll r, vector <ll> &h) {
    if (l == 0) {
        return h[r - 1];
    }
    return sub(h[r - 1], mul(h[l - 1], power[r - 1 - (l - 1)]));
}
///R
void cntRhash(const string &s, vector <ll> &rh) {
    ll n = s.size();
    if (n == 0) {
        return;
    }
    rh.resize(n);
    rh[0] = code[s[0] - 'a'];
    for (ll i = 1; i < n; ++i) {
        rh[i] = sum(rh[i - 1], mul(code[s[i] - 'a'], power[i]));
    }
}

ll cntRhash(const string &s) {
    ll res = 0;
    ll n = s.size();
    if (n == 0) {
        return -1;
    }
    for (ll i = 0; i < n; ++i) {
        res = sum(res, mul(code[s[i] - 'a'], power[i]));
    }
    return res;
}

ll getRhash(ll l, ll r, vector <ll> &rh) {
    if (l == 0) {
        return rh[r - 1];
    }
    return mul(sub(rh[r - 1], rh[l - 1]), rev(power[l]));
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    start();
    cin >> s;
    vector <ll> hs;
    cnthash(s, hs);
    int q;
    cin >> q;
    while (q--) {
        int len, a, b;
        cin >> len >> a >> b;
        cout << (gethash(a, a + len, hs) == gethash(b, b + len, hs) ? "yes" : "no") << '\n';
    }
    return 0;
}

/**


**/
