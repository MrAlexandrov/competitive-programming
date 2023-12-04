#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int n;
    cin >> n;
    vector <ll> a(n);
    ll score = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        score += abs(a[0] - a[i]);
    }
    cout << score << ' ';
    for (int i = 1; i < n; ++i) {
        score += 1LL * (a[i] - a[i - 1]) * i;
        score -= 1LL * (a[i] - a[i - 1]) * (n - i);
        cout << score << ' ';
    }
    return 0;
}

/**


**/
