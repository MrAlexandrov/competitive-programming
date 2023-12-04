#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    string s;
    cin >> s;
    string t;
    cin >> t;
    vector <int> cnt_s(26, 0);
    vector <int> cnt_t(26, 0);
    for (const char &i : s) {
        cnt_s[int(i - 'a')]++;
    }
    for (const char &j : t) {
        cnt_t[int(j - 'a')]++;
    }
    cout << (cnt_s == cnt_t ? "YES" : "NO");
    return 0;
}

/**


**/
