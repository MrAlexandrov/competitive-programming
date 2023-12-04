#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <int> manacher_odd(const string &s) {
    int n = (int) s.size();
    vector <int> d(n, 1);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r)
            d[i] = min(r - i + 1, d[l + r - i]);
        while (i - d[i] >= 0 && i + d[i] < n && s[i - d[i]] == s[i + d[i]])
            ++d[i];
        if (i + d[i] - 1 > r)
            l = i - d[i] + 1, r = i + d[i] - 1;
    }
    return d;
}

vector <int> manacher_even(const string &s) {
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
    string s;
    cin >> s;
    int n = s.size();
    vector <int> even = manacher_even(s), odd = manacher_odd(s);
    ll ans = 0;
    for (const int &i : even) {
        ans += i;
    }
    for (const int &i : odd) {
        ans += i;
    }
    cout << ans;
    return 0;
}

/**


**/
