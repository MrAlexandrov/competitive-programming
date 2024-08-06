#include <bits/stdc++.h>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, s, m;
        cin >> n >> s >> m;
        bool ok = false;
        int l, r;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cin >> l >> r;
            if (l - cur >= s) {
                ok = true;
            }
            cur = r;
        }
        if (m - cur >= s) {
            ok = true;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}

/*


*/