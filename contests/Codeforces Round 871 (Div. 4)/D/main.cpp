#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool can(int n, int m) {
    if (n == m) {
        return true;
    } else {
        if (n % 3 == 0) {
            return (can(n / 3, m) | can(2 * n / 3, m));
        } else {
            return false;
        }
    }
}

string solve() {
    int res = 0;
    int n, m;
    cin >> n >> m;
    return (can(n, m) ? "YES" : "NO");
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
