#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int &i : a) {
        cin >> i;
    }
    int m;
    cin >> m;
    vector <int> b(m);
    for (int &j : b) {
        cin >> j;
    }
    vector <int> res(n + m);
    int it1 = 0, it2 = 0;
    while (it1 < n && it2 < m) {
        if (a[it1] < b[it2]) {
            res[it1 + it2] = a[it1];
            ++it1;
        } else {
            res[it1 + it2] = b[it2];
            ++it2;
         }
    }
    while (it1 < n) {
        res[it1 + it2] = a[it1];
        ++it1;
    }
    while (it2 < m) {
        res[it1 + it2] = b[it2];
        ++it2;
    }
    for (const int &i : res) {
        cout << i << ' ';
    }
    return 0;
}

/**


**/
