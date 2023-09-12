#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve() {
    int res = 0;
    int n;
    cin >> n;
    int now = 0;
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x == 0) {
            now++;
        } else {
            res = max(res, now);
            now = 0;
        }
    }
    res = max(res, now);
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
