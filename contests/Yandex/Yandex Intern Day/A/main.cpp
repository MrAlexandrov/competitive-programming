#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    string s;
    cin >> s;
    s += '+';
    int n = s.size();
    string temp = "";
    bool add = true;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if ('0' <= s[i] && s[i] <= '9') {
            temp += s[i];
        } else {
            ll now = stoll(temp);
            if (add) {
                ans += now;
            } else {
                ans -= now;
            }
            temp = "";
            add = s[i] == '+';
        }
    }
    cout << ans;
    return 0;
}

/**


**/
