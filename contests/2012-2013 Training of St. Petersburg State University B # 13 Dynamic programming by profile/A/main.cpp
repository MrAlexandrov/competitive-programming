#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll M = (1 << 30) + 1;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("m3.in", "r", stdin);
    freopen("m3.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    if (n < m) swap(n, m);
    vector <vector <vector <ll>>> dp(2, vector <vector <ll>> (m + 1, vector <ll>(1 << (m + 1), 0)));
    /// dp[i][j][mask] - ответ, если мы
    /// находимся на i-м слое,
    /// на j-й строчке,
    /// на предыдущем слое был профиль mask.
    dp[0][0][0] = 1;
    int ind = 0;
    for (int i = 0; i < n; ++i, ind ^= 1) {
        for (int j = 0; j < m; ++j) {
            for (int mask = 0; mask < (1 << (m + 1)); ++mask) {
                for (int bit = 0; bit < 2; ++bit) {
                    //cout << i << ' ' << j << ' ' << mask << ' ' << bit << endl;
                    if (i == 0 || j == 0 || (((mask >> (j - 1)) & 7) != bit * 7)) {
                        int to = (mask & ~(1 << j)) | (bit << j);
                        dp[ind][j + 1][to] += dp[ind][j][mask];
                        dp[ind][j + 1][to] %= M;
                        /*if (dp[i][j][mask]) {
                            cout << "dp[" << i << "][" << j << "][" << mask << "] = " << dp[i][j][mask] << endl;
                            cout << "added to dp[" << i << "][" << j + 1 << "][" << to << "]" << endl;
                        }*/
                    }
                }
            }
        }
        for (int j = 0; j < m + 1; ++j) {
            for (int mask = 0; mask < (1 << (m + 1)); ++mask) {
                dp[ind ^ 1][j][mask] = 0;
            }
        }
        for (int mask = 0; mask < (1 << (m + 1)); ++mask) {
            int to = (mask & ~(1 << m)) << 1;
            dp[ind ^ 1][0][to] += dp[ind][m][mask];
            dp[ind ^ 1][0][to] %= M;
        }
    }
    ll ans = 0;
    for (int mask = 0; mask < (1 << (m + 1)); ++mask) {
        //cout << dp[n][0][mask] << endl;
        ans += dp[ind][0][mask];
        ans %= M;
    }
    cout << ans << endl;
    return 0;
}

/**


**/
