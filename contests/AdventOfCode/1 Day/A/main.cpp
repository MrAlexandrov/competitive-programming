#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int first_last(const string &s) {
    int first = -1;
    int last = -1;
    for (char i : s) {
        if ('0' <= i && i <= '9') {
            last = i - '0';
            if (first == -1) {
                first = i - '0';
            }
        }
    }
    return first * 10 + last;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int ans = 0;
    string s;
    while (cin >> s) {
        ans += first_last(s);
    }
    cout << ans;
    return 0;
}

/**
54081

**/
