#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int n, m, q;
    cin >> n >> m >> q;
    unordered_map <int, int> who[2];
    int x;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        who[0][x]++;
    }
    ans = n;
    for (int i = 0; i < m; ++i) {
        cin >> x;
        int was = abs(who[0][x] - who[1][x]);
        who[1][x]++;
        int now = abs(who[0][x] - who[1][x]);
        ans -= was;
        ans += now;
    }
    int type;
    char player;
    int card;
    while (q--) {
        cin >> type >> player >> card;
        int was = abs(who[0][card] - who[1][card]);
        who[player - 'A'][card] += type;
        int now = abs(who[0][card] - who[1][card]);
        ans -= was;
        ans += now;
        cout << ans << ' ';
    }
    return 0;
}

/**


**/
