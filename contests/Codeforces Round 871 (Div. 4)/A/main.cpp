#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const string s = "codeforces";

int solve() {
    int res = 0;
    string x;
    cin >> x;
    for (int i = 0; i < 10; ++i) {
        if (x[i] != s[i]) {
            res++;
        }
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
