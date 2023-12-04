#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    int mn = INF;
    for (int &i : a) {
        cin >> i;
        mn = min(mn, i);
    }
    int cnt_front = (a[0] == mn);
    int cnt_back = (a[n - 1] == mn);
    for (int i = 0; i < n - 1; ++i) {
        cnt_front += (a[i] != mn && a[i + 1] == mn);
        cnt_back += (a[i] == mn && a[i + 1] != mn);
    }
    if (cnt_front > 1 || cnt_back > 1) {
        cout << "-1\n";
        return;
    }
    for (int i = n - 1; a[i] != mn; --i) {
        if (a[i - 1] > a[i]) {
            cout << "-1\n";
            return;
        }
    }
    for (int ans = 0; ans < n; ++ans) {
        if (a[ans] == mn) {
            cout << ans << '\n';
            return;
        }
    }
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
1. Все минимальные элементы должны стоять подряд
2. После минимальных элементов всё должно быть уже упорядочено

5
5
1 8 1 8 1
5
8 1 8 1 8
5
1 1 8 1 1
5
1 8 8 8 1
5
8 1 1 1 8

**/
