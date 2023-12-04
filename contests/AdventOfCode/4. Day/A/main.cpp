#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve() {
    string temp;
    cin >> temp >> temp;
    vector <int> a(10);
    for (int &i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    cin >> temp;
    vector <int> b(25);
    for (int &i : b) {
        cin >> i;
    }
    sort(b.begin(), b.end());
    vector <int> c;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c));
    int k = c.size();
    if (k) {
        return (1 << (k - 1));
    } else {
        return 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int t = 193;
    ///cin >> t;
    int ans = 0;
    while (t--) {
        ans += solve();
    }
    cout << ans;
    return 0;
}

/**


**/
