#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int n;
    cin >> n;
    vector <string> a(n);
    for (string &i : a) {
        cin >> i;
    }
    cout << "Initial array:\n";
    for (int i = 0; i < n; ++i) {
        if (i) cout << ", ";
        cout << a[i];
    }
    cout << '\n';
    cout << "**********\n";
    vector <string> bucket[10];
    int m = a[0].size();
    for (int it = 0; it < m; ++it) {
        cout << "Phase " << it + 1 << '\n';
        int j = m - it - 1;
        for (int i = 0; i < n; ++i) {
            bucket[a[i][j] - '0'].push_back(a[i]);
        }
        int ptr = 0;
        for (int i = 0; i < 10; ++i) {
            int sz = bucket[i].size();
            cout << "Bucket " << i << ": ";
            if (!sz) cout << "empty";
            for (int j = 0; j < sz; ++j) {
                if (j) cout << ", ";
                cout << bucket[i][j];
                a[ptr++] = bucket[i][j];
            }
            bucket[i].clear();
            cout << '\n';
        }
        cout << "**********\n";
    }
    cout << "Sorted array:\n";
    for (int i = 0; i < n; ++i) {
        if (i) cout << ", ";
        cout << a[i];
    }
    return 0;
}

/**


**/
