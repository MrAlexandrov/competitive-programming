#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector <vector <bool> > dp(n + 1, vector <bool> (m + 1, true));
    dp[0][0] = false;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            dp[i][j] = !((i > 0 ? dp[i - 1][j] : true) &&
                         (j > 0 ? dp[i][j - 1] : true) &&
                         (i > 1 ? dp[i - 2][j] : true) &&
                         (j > 1 ? dp[i][j - 2] : true) &&
                         (i > 1 && j > 0 ? dp[i - 2][j - 1] : true) &&
                         (i > 0 && j > 1 ? dp[i - 1][j - 2] : true));
        }
    }
    cout << (dp[n][m] ? "Win" : "Loose");
    return 0;
}

/**


**/
