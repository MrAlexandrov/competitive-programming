#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    ll n, k;
    cin >> n >> k;
    vector <ll> a(n, -1);
    ll el = n;
    for (int i = 0; i < n; ++i) {
        if (k >= n - 1 - i) {
            a[i] = el--;
            k -= n - 1 - i;
        }
    }
    assert(k == 0);
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == -1) {
            a[i] = el--;
        }
    }
    assert(el == 0);
    for (ll i : a) {
        cout << i << ' ';
    }
    return 0;
}

/**


**/
