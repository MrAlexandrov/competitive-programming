#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e3 + 7;

int n, m;
int field[MAXN][MAXN];
bool was[MAXN][MAXN];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

bool check(int i, int j) {
     return (0 <= i && i < n && 0 <= j && j < m && !was[i][j]);
}

int DFS(int i, int j) {
    int res = field[i][j];
    was[i][j] = true;
    for (int k = 0; k < 4; ++k) {
        int to_i = i + dx[k];
        int to_j = j + dy[k];
        if (check(to_i, to_j)) {
            res += DFS(to_i, to_j);
        }
    }
    return res;
}

int solve() {
    int res = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> field[i][j];
            was[i][j] = (field[i][j] == 0 ? true : false);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!was[i][j]) {
                res = max(res, DFS(i, j));
            }
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
