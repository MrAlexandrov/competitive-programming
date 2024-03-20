#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int x;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        ans += x / 4;
        ans += (x % 4);
        if (x % 4 == 3) --ans;
    }
    cout << ans;
    return 0;
}

/**
0   0
1   1
2   2
3   2 = min(3, 1 + 1)

4   1
5   2
6   3
7   3

8   2

**/
