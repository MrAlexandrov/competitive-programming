#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 2e6;

int solve() {
    int res = 0;
    int n;
    cin >> n;
    int a = INF;
    int b = INF;
    int ab = INF;
    int x;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> x >> s;
        if (s == "00") {
            continue;
        }
        if (s == "11") {
            ab = min(ab, x);
            continue;
        }
        if (s == "10") {
            a = min(a, x);
            continue;
        }
        if (s == "01") {
            b = min(b, x);
            continue;
        }
    }
    res = min(ab, a + b);
    return res == INF ? -1 : res;
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
