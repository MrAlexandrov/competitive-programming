#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int n;
    cin >> n;
    int ans = 1;
    for (int i = 2; i <= n; ++i) {
        ans *= i;
    }
    cout << ans;
    return 0;
}

/**


**/
