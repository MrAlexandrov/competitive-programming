#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector <int> a(n);
    int cnt_odd = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt_odd += static_cast<bool>(a[i] & 1);
    }
    assert(cnt_odd > 0);
    string ans;
    for (int i = 0; i < n - 1; ++i) {
        ans += static_cast<char>(43);
    }
    if (cnt_odd % 2 == 0) {
        for (int i = 0; i < n; ++i) {
            if (a[i] & 1) {
                ans[i] = static_cast<char>(120);
                break;
            }
        }
    }
    cout << ans;
    return 0;
}

/**


**/
