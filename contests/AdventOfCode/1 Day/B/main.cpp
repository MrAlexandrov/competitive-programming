#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <string> digits = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int first_last_update(string &s) {
    int n = s.size();
    vector <pair <int, int>> a; /// ind, val
    for (int i = 0; i < n; ++i) {
        if ('0' <= s[i] && s[i] <= '9') {
            a.push_back({i, s[i] - '0'});
        }
    }
    for (int i = 0; i < digits.size(); ++i) {
        string &digit = digits[i];
        if (n < digit.size()) continue;
        for (int j = 0; j < n - digit.size() + 1; ++j) {
            bool ok = true;
            for (int k = j; k < j + digit.size(); ++k) {
                if (s[k] != digit[k - j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                a.push_back({j, i + 1});
            }
        }
    }
    sort(a.begin(), a.end());
    return a[0].second * 10 + a.back().second;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int ans = 0;
    string s;
    while (cin >> s) {
        cout << s << ' ' << first_last_update(s) << endl;
        ans += first_last_update(s);
    }
    cout << ans;
    return 0;
}

/**
54649

**/
