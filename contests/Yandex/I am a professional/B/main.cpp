#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    ll n, k, a;
    cin >> n >> k >> a;
    ll ans = n;
    ll down = n / k;
    ans = min(ans, n - down * k + down * a);
    ll up = (n + k - 1) / k;
    ans = min(ans, up * k - n + up * a);
    cout << ans;
    return 0;
}

/**


**/
