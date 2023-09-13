#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve() {
    string res;
    int n;
    string s;
    cin >> n;
    cin >> s;
    int half = n / 2;
    int diff = 0;
    for (int i = 0; i < half; ++i) {
        diff += (s[i] != s[n - i - 1]);
    }
    for (int i = 0; i < diff; ++i) {
        res += '0';
    }
    if (n & 1) {
        for (int i = diff; i <= n - diff; i++) {
            res += '1';
        }
    } else {
        for (int i = diff; i <= n - diff; i++) {
            res += (i % 2 == diff % 2) ? '1' : '0';
        }
    }
    for (int i = n - diff + 1; i <= n; ++i) {
        res += '0';
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}

/**


**/
