#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int n, m, q;
    cin >> n >> m >> q;
    vector <string> name(m);
    unordered_map <string, int> num;
    for (int j = 0; j < m; ++j) {
        cin >> name[j];
        num[name[j]] = j;
    }
    vector <vector <int>> a(n, vector <int>(m));
    vector <int> mn(m, INF);
    vector <int> mx(m, -INF);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            mn[j] = min(mn[j], a[i][j]);
            mx[j] = max(mx[j], a[i][j]);
        }
    }
    string column;
    char character;
    int val;
    while (q--) {
        cin >> column >> character >> val;
        int j = num[column];
        if (character == '>') {
            mn[j] = max(mn[j], val + 1);
        } else {
            mx[j] = min(mx[j], val - 1);
        }
    }
    vector <bool> ans (n, true);
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (!(mn[j] <= a[i][j] && a[i][j] <= mx[j])) {
                ans[i] = false;
            }
        }
    }
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        if (ans[i]) {
            for (int j = 0; j < m; ++j) {
                result += a[i][j];
            }
        }
    }
    cout << result;
    return 0;
}

/**


**/
