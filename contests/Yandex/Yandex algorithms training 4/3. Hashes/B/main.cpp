#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void z(const string &s, vector <ll> &z) {
    ll n = s.size();
    z.resize(n);
    z[0] = 0;
    for (ll i = 1, l = 0, r = 1; i < n; ++i) {
        z[i] = min(max(0LL, r - i), z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] > r) {
            l = i, r = i + z[i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    string s;
    cin >> s;
    vector <ll> zed;
    z(s, zed);
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (i + zed[i] == n) {
            cout << i << ' ';
            return 0;
        }
    }
    cout << n;
    return 0;
}

/**


**/
