#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(const pair <int, int> &a, const pair <int, int> &b) {
    if (a.second == b.second) {
        return a.first > b.first;
    } else {
        return a.second < b.second;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int n;
    cin >> n;
    vector <pair <int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), cmp);
    int ans = 0;
    int prev = 0;
    for (const pair <int, int> &i : a) {
        if (prev < i.first) {
            ++ans;
            prev = i.second;
        }
    }
    cout << ans;
    return 0;
}

/**


**/
