#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int n;
    cin >> n;
    vector <bool> a(n + 1);
    char x;
    for (int i = 1; i < n + 1; ++i) {
        cin >> x;
        a[i] = x - 'A';
    }
    vector <vector <int>> ans(n + 1, vector <int> (2, 0));              // Расстояние до ближайшего начальника, разговаривающиего на определённом языке
    //vector <int> cnt(n + 1, 0);
    int m = 2 * (n + 1);
    vector <int> p(m);
    for (int i = 0; i < m; ++i) {
        cin >> p[i];
    }
    stack <int> tree;
    tree.push(0);
    //cnt[0]++;
    for (int i = 1; i < m; ++i) {
        int cur = p[i];
        int prev = tree.top();
        if (cur == prev) {
            tree.pop();
            //cnt[cur]++;
            continue;
        }
        if (prev == 0) {
            tree.push(cur);
            //cnt[cur]++;
            ans[cur][0] = ans[cur][1] = 1;
            continue;
        }
        tree.push(cur);
        //cnt[cur]++;
        for (int j = 0; j < 2; ++j) {
            ans[cur][j] = (a[prev] == j ? 1 : ans[prev][j] + 1);
        }
    }
    for (int i = 1; i < n + 1; ++i) {
        cout << ans[i][a[i]] - 1 << ' ';
    }
    return 0;
}

/**


**/
