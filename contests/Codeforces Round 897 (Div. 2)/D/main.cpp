#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve() {
    string res = "NO";
    int n, k;
    cin >> n >> k;
    vector <pair <int, int>> a(n);
    vector <int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        a[i] = {b[i], i + 1};
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        cout << a[i].first << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; ++i) {
        cout << a[i].second << ' ';
    }
    cout << '\n' << '\n';
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
