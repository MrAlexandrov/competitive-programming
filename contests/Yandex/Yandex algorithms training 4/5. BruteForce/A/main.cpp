#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool next(vector <int> &ans) {
    int n = ans.size();
    int i = n - 1;
    for (; i > 0; --i) {
        if (ans[i - 1] < ans[i]) {
            break;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int n;
    cin >> n;
    vector <int> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[i] = i + 1;
    }
    do {
        for (int &i : ans) {
            cout << i;
        }
        cout << '\n';
    }
    while (next(ans));
    return 0;
}

/**
12345
 ...
35412
35421
41235

**/
