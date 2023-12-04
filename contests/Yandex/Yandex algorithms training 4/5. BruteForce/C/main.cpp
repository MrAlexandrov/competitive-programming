#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 20;
const int INF = 1e9 + 7;

int g[N][N]{};
int n;
int res = 0;
int ans[N];
int cur = 0;

int G(int n) {
    return n ^ (n >> 1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }
    int ans = 0;
    int ind = 0;
    int prev = 0;
    int cur = 0;
    for (int x = 1; x < (1 << n); ++x) {
        int grey = G(x);
        int change = grey ^ prev;
        int changed_ind = 0;
        for (changed_ind = 0; changed_ind < n; ++changed_ind) {
            if ((bool)(change & (1 << changed_ind))) {
                break;
            }
        }
        if ((bool)(grey & (1 << changed_ind))) {
            for (int i = 0; i < n; ++i) {
                if ((bool)(prev & (1 << i))) {
                    cur -= g[changed_ind][i];
                } else {
                    cur += g[changed_ind][i];
                }
            }
        } else {
            for (int i = 0; i < n; ++i) {
                if ((bool)(prev & (1 << i))) {
                    cur += g[changed_ind][i];
                } else {
                    cur -= g[changed_ind][i];
                }
            }
        }
        if (ans < cur) {
            ans = cur;
            ind = grey;
        }
        prev = grey;
    }
    cout << ans << '\n';
    for (int i = 0; i < n; ++i) {
        cout << (bool)(ind & (1 << i)) + 1 << ' ';
    }
    return 0;
}

/**


**/
