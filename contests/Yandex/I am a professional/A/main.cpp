#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    ll M;
    cin >> M;
    ll sq = sqrt(M);
    for (ll i = max(0LL, sq - 5); i <= min((ll)1e9, sq + 5); ++i) {
        if (i * i < M && M < (i + 1) * (i + 1)) {
            cout << i << ' ' << i + 1;
            return 0;
        }
    }
    for (ll i = max(0LL, sq - 5); i <= min((ll)1e9, sq + 5); ++i) {
        if (i * i < M && M < (i + 2) * (i + 2)) {
            cout << i << ' ' << i + 2;
            return 0;
        }
    }
    return 0;
}

/**


**/
