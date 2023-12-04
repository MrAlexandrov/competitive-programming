#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll p = n / a;
    ll q = n % a;
    return ((b - a) * p >= q ? "YES" : "NO");
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
