#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll str_to_ll(const string &s) {
    ll res = 0;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        res *= 10;
        res += s[i] - '0';
    }
    return res;
}

string ll_to_str(const ll &t) {
    ll x = t;
    string res;
    while (x > 0) {
        int last = x % 10;
        x /= 10;
        res += (char)(last + '0');
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    string t, last;
    cin >> t;
    ll num = str_to_ll(t);
    int n = t.size();
    for (int add = 0; add < 10; ++add) {
        ll num_s = num + add;
        string s = ll_to_str(num_s);
        last = s;
        for (int i = 0; i < n / 2; ++i) {
            char a = last[i], b = last[n - i - 1];
            if (a > b) {
                last[n - i - 1] = a;
                cout << str_to_ll(last) - num;
                return 0;
            }
        }
    }
    return 0;
}

/**


**/
