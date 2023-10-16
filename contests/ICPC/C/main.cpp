#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int k;
    cin >> k;
    vector <int> a(k);
    int sum = 0;
    int sum_exterior = 0;
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        sum += a[i];
        sum_exterior += 180 - a[i];
    }
    if (sum_exterior > 360) {
        cout << "-1";
        return 0;
    }
    if (sum_exterior == 360) {
        cout << k << ' ' << k;
        return 0;
    }
    int need = 360 - sum_exterior;
    int min_ans = ((need + 179 - 1) / 179);
    int max_ans = need;
    cout << min_ans + k << ' ' << max_ans + k;
    return 0;
}

/**


**/
