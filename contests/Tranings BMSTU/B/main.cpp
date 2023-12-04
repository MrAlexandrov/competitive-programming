#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int n, m, T;
    cin >> n >> m >> T;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ptr = 0;
    int ans = 0;
    while (ptr < n) {
        int cnt = 0;
        int element = a[ptr];
        while (ptr < n && a[ptr] <= element + T && cnt < m) {
            ++ptr;
            ++cnt;
        }
        ++ans;
    }
    cout << ans;
    return 0;
}

/**
4 4 3
1 2 5 9

**/
