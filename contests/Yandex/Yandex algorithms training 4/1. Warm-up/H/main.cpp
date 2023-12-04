#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int a, b, n;
    cin >> a >> b >> n;
    cout << (a > (b + n - 1) / n ? "Yes" : "No");
    return 0;
}

/**


**/
