#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector <vector <int>> dp(2, vector <int> (m + 1, 0));
    int x;
    int ans = 0;
    int i = 1;
    for (int ptr_i = 1; ptr_i <= n; ++ptr_i, i ^= 1) {
        for (int j = 1; j <= m; ++j) {
            cin >> x;
            dp[i][j] = (x ? min({dp[i ^ 1][j - 1], dp[i ^ 1][j], dp[i][j - 1]}) + 1 : 0);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
    return 0;
}

/**


**/
