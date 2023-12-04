#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int n = 100;
    string s;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        string game, num;
        cin >> game >> num;
        map <char, int> m;
        int cnt;
        string color;
        while (true) {
            cin >> cnt >> color;
            m[color[0]] = max(m[color[0]], cnt);
            if (color.back() != ',' && color.back() != ';') break;
        }
        ans += m['r'] * m['g'] * m['b'];
    }
    cout << ans;
    return 0;
}

/**
67953

**/
