#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 140;
vector <string> a(N);
vector <vector <bool>> checked(N, vector <bool>(N, false));

bool is_num(char x) {
    return ('0' <= x && x <= '9');
}

int go(int x, int y) {
    while (is_num(a[x][y]) && is_num(a[x][y - 1])) {
        --y;
    }
    int res = 0;
    for (int j = y; is_num(a[x][j]); ++j) {
        res *= 10;
        res += a[x][j] - '0';
        checked[x][j] = true;
    }
    return res;
}

int check(int x, int y) {
    int cnt = 0;
    int res = 1;
    for (int i = x - 1; i <= x + 1; ++i) {
        for (int j = y - 1; j <= y + 1; ++j) {
            if (!(0 <= i && i < N && 0 <= j && j < N)) continue;
            if (!checked[i][j] && is_num(a[i][j])) {
                res *= go(i, j);
                ++cnt;
            }
        }
    }
    return (cnt > 1 ? res : 0);
}

void solve() {
    int ans = 0;
    int n = N;
    for (string &s : a) {
        cin >> s;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == '*') {
                ans += check(i, j);
            }
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
69527306

**/
