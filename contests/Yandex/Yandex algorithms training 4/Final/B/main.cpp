#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

mt19937_64 rnd(time(0));

const ll N = 2e5 + 8;
const ll M = 1e9 + 7;
const ll P = 9901;
///const ll P = 10;
const ll ABC = 26;

unordered_map <char, ll> code;
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
    unordered_set <ll> s;
    while (s.size() < 2 * ABC) {
        s.insert(myrnd(1e3, 1e4 + 1));
    }
    for (int i = 0; i < ABC; ++i) {
        code[(char)(i + 'a')] = *s.begin();
        s.erase(s.begin());
    }
    for (int i = 0; i < ABC; ++i) {
        code[(char)(i + 'A')] = *s.begin();
        s.erase(s.begin());
    }
    assert(s.empty());
    /*for (auto i : s) {
        code.push_back(i);
    }*/
    /*for (int i = 0; i < ABC; ++i) {
        code.push_back(i + 1);
    }*/
    for (ll i = 0; i < N; ++i) {
        power.push_back(mul(power.back(), P));
    }
}

void cnthash(string s, vector <ll> &h) {
    ll n = s.size();
    if (n == 0) {
        return;
    }
    h.resize(n);
    /*for (ll i = 0; i < n; ++i) {
        s[i] -= 'a';
    }*/
    h[0] = code[s[0]];
    for (ll i = 1; i < n; ++i) {
        h[i] = mul(h[i - 1], P);
        h[i] = sum(h[i], code[s[i]]);
    }
}

ll cnthash(string s) {
    ll res = 0;
    ll n = s.size();
    if (n == 0) {
        return -1;
    }
    /*for (ll i = 0; i < n; ++i) {
        s[i] -= 'a';
    }*/
    for (ll i = 0; i < n; ++i) {
        res = sum(res, mul(code[s[i]], power[n - i - 1]));
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
void cntRhash(string s, vector <ll> &rh) {
    ll n = s.size();
    if (n == 0) {
        return;
    }
    rh.resize(n);
    /*for (ll i = 0; i < n; ++i) {
        s[i] -= 'a';
    }*/
    rh[0] = code[s[0]];
    for (ll i = 1; i < n; ++i) {
        rh[i] = sum(rh[i - 1], mul(code[s[i]], power[i]));
    }
}

ll cntRhash(string s) {
    ll res = 0;
    ll n = s.size();
    if (n == 0) {
        return -1;
    }
    /*for (ll i = 0; i < n; ++i) {
        s[i] -= 'a';
    }*/
    for (ll i = 0; i < n; ++i) {
        res = sum(res, mul(code[s[i]], power[i]));
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector <ll> h, rh;
    cnthash(s, h);
    cntRhash(s, rh);
    /*for (int i = 0; i < n; ++i) {
        cout << "i = " << i << '\n';
        for (int j = 0; j <= i; ++j) {
            cout << gethash(0, j + 1, h) << ' ' << getRhash(i - j, i + 1, rh) << '\n';
        }
    }
    return 0;*/
    vector <int> ans(n);
    for (int i = 0; i < n; ++i) {
        ///cout << "i = " << i << '\n';
        int l = 0, r = i + 2;
        while (r - l > 1) {
            int m = (l + r) / 2;
            ///cout << "m = " << m << ", hash = " << gethash(0, m, h) << ", Rhash = " << getRhash(i + 1 - m, i + 1, rh) << '\n';
            if (gethash(0, m, h) == getRhash(i + 1 - m, i + 1, rh)) {
                l = m;
            } else {
                r = m;
            }
        }
        ans[i] = l;
    }
    for (const int &i : ans) {
        cout << i << ' ';
    }
    return 0;
}

/**
5
012345
bbabb

1 0 0 0 0 0 0 0 0 10 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0
1 0 0 0 0 0 0 0 0 10 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0

**/
