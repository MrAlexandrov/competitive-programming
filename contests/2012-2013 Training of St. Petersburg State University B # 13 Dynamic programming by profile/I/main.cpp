#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const ld PI = 3.141592653589793238462643383279;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("b3.in", "r", stdin);
    ///freopen("b3.out", "w", stdout);
    cout.precision(20);
    int n, m;
    cin >> n >> m;
    ld ans = 1;
    for (int a = 1; a <= (n + 1) / 2; ++a) {
        ld cur = 1;
        for (int b = 1; b <= (m + 1) / 2; ++b) {
            ld x = cos(PI * a / (n + 1));
            ld y = cos(PI * b / (m + 1));
            cur *= 4 * x * x + 4 * y * y;
        }
        ans *= cur;
    }
    cout << (long long)ans;
    return 0;
}

/**


**/
