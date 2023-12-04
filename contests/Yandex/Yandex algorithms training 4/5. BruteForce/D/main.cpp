#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 10;
const int INF = 1e9 + 7;

ll dp[N][1 << N];
ll g[N][N]{};
int n;

void tsp() {
    int s = (1 << (n - 1)) - 1;
    int path[s][n - 1]{};
    int local_sum[s][n - 1];
    for (int i = 0; i < s; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            local_sum[i][j] = -1;
        }
    }
    ///
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
            if (g[i][j] == 0) {
                g[i][j] = INF;
            }
        }
    }

    return 0;
}

/**


**/
