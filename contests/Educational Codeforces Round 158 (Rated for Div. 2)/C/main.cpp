#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int max_zero(int x) {
    bool was = false;
    int res = 0;
    for (int i = 31; i >= 0; --i) {
        if (was && (x & (1 << i)) == 0) {
            res += (1 << i);
        }
        if (!was && (x & (1 << i))) {
            was = true;
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector <int> ans;
    int mx = *max_element(a.begin(), a.end());
    int mn = *min_element(a.begin(), a.end());
    while (mx != mn) {
        int zero = max_zero(mx);
        mx += zero;
        mx >>= 1;

        mn += zero;
        mn >>= 1;
        ans.push_back(zero);
    }
    cout << ans.size() << '\n';
    if (ans.size() <= n) {
        for (const int &i : ans) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/**
110
100

**/
