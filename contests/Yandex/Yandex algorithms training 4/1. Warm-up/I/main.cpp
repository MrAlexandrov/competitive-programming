#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void ans(bool ok) {
    cout << (ok ? "yes" : "no");
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    vector <pair <char, char>> braces = {{'(', ')'},
                                         {'{', '}'},
                                         {'[', ']'}};
    string s;
    cin >> s;
    stack <char> stk;
    for (const char &c : s) {
        for (int i = 0; i < 3; ++i) {
            if (c == braces[i].first) {
                stk.push(c);
            } else if (c == braces[i].second) {
                if (stk.empty()) {
                    ans(false);
                }
                if (stk.top() != braces[i].first) {
                    ans(false);
                } else {
                    stk.pop();
                }
            }
        }
    }
    ans(stk.empty() ? true : false);
    return 0;
}

/**


**/
