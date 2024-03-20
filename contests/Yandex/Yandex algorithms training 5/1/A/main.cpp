#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int intersect(int lv, int rv, int lm, int rm) {
    if (rv < lm || rm < lv) {
        return 0;
    }
    if (lv <= lm && rm <= rv) {
        return rm - lm + 1;
    }
    if (lm <= lv && rv <= rm) {
        return rv - lv + 1;
    }
    if (rv < rm) {
        return max(0, rv - lm + 1);
    } else {
        return max(0, rm - lv + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int P, V;
    int Q, M;
    cin >> P >> V;
    cin >> Q >> M;
    int lv = P - V, rv = P + V;
    int lm = Q - M, rm = Q + M;
    int ans = (rv - lv + 1) + (rm - lm + 1);
    ans -= intersect(lv, rv, lm, rm);
    cout << ans << endl;
    return 0;
}

/**


**/
