#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int n, b;
    cin >> n >> b;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector <int> d(n + 1, -1);
    for (int i = 0; i < n; ++i) {
        d[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (a[j] <= a[i] && a[i] <= a[j] + b && d[j] + 1 > d[i]) {
                d[i] = d[j] + 1;
                cout << 1 << ' ';
            } else {
                cout << 0 << ' ';
            }
        }
        cout << endl;
    }
    cout << *max_element(d.begin(), d.end());
    return 0;
}

/**


**/
