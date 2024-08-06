#include <bits/stdc++.h>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tests;
    cin >> tests;
    while (tests--) {
        string s;
        cin >> s;
        string t;
        cin >> t;
        int n = s.size();
        int m = t.size();
        int i = 0;
        int j = 0;
        while (i < n && j < m) {
            if (s[i] == t[j]) {
                ++j;
            } else if (s[i] == '?') {
                s[i] = t[j];
                ++j;
            }
            ++i;
        }
        if (j == m) {
            for (int i = 0; i < n; ++i) {
                if (s[i] == '?') {
                    s[i] = 'a';
                }
            }
            cout << "YES" << '\n';
            cout << s << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}

/*


*/