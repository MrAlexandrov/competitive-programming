#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 140;
vector <string> a(N);

int check(int x, int y, int len) {
    int res = 0;
    for (int j = y; j < y + len; ++j) {
        res *= 10;
        res += a[x][j] - '0';
    }
    bool ok = false;
    for (int i = x - 1; i <= x + 1; ++i) {
        for (int j = y - 1; j <= y + len; ++j) {
            if (!(0 <= i && i < N && 0 <= j && j < N)) continue;
            if (!('0' <= a[i][j] && a[i][j] <= '9' || a[i][j] == '.')) ok = true;
        }
    }
    return (ok ? res : 0);
}

void solve() {
    int ans = 0;
    int n = N;
    for (string &s : a) {
        cin >> s;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int beg = j;
            bool ok = false;
            while ('0' <= a[i][j] && a[i][j] <= '9') {
                ++j;
                ok = true;
            }
            if (ok) ans += check(i, beg, j - beg);
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/**
521515

**/
