#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    long double ans = 1;
    int x;
    cin >> x;
    for (int i = 1; i <= x; ++i) {
        for (int j = i; j <= x; ++j) {
            for (int k = 1; k <= x; ++k) {
                ans *= (i + j + k - 1) / (i + j + k - 2);
            }
        }
    }
    cout << ans;
    return 0;
}

/**


**/
