#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 4e4 + 7;
vector <pair <int, int>> a(MAXN);

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.begin() + n);
    vector <int> res(n);
    for (int i = 0; i < n; ++i) {
        //cout << a[i].first - (n - i) << ' ';
        //cout << a[i].second << ' ';
        res[a[i].second] = n - i;
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << ' ';
    }
    cout << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/**


**/
