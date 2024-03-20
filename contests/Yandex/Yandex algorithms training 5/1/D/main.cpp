#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int n = 8;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    vector <vector <bool>> good(n, vector <bool> (8, true));
    vector <string> table(8);
    for (int i = 0; i < n; ++i) {
        cin >> table[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (table[i][j] == 'R') {
                for (int ii = i + 1; ii < n && table[ii][j] == '*'; ++ii) {
                    good[ii][j] = false;
                }
                for (int ii = i - 1; ii >= 0 && table[ii][j] == '*'; --ii) {
                    good[ii][j] = false;
                }
                for (int jj = j + 1; jj < n && table[i][jj] == '*'; ++jj) {
                    good[i][jj] = false;
                }
                for (int jj = j - 1; jj >= 0 && table[i][jj] == '*'; --jj) {
                    good[i][jj] = false;
                }
            }
            if (table[i][j] == 'B') {
                for (int ii = i - 1, jj = j - 1; ii >= 0 && jj >= 0 && table[ii][jj] == '*'; --ii, --jj) {
                    good[ii][jj] = false;
                }
                for (int ii = i - 1, jj = j + 1; ii >= 0 && jj < n && table[ii][jj] == '*'; --ii, ++jj) {
                    good[ii][jj] = false;
                }
                for (int ii = i + 1, jj = j - 1; ii < n && jj >= 0 && table[ii][jj] == '*'; ++ii, --jj) {
                    good[ii][jj] = false;
                }
                for (int ii = i + 1, jj = j + 1; ii < n && jj < n && table[ii][jj] == '*'; ++ii, ++jj) {
                    good[ii][jj] = false;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans += (table[i][j] == '*' && good[i][j]);
        }
    }
    cout << ans;
    return 0;
}

/**


**/
