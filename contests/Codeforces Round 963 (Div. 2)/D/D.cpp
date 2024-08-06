#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<int> t;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int64_t n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto& e: a) cin >> e;
        int need = (n % k);
        if (!need) {
            need = k;
        }
        vector<int> z(k);
        for (int i = 0; i < n; ++i) {
            z[i % k] = max(z[i % k], a[i]);
        }
        sort(z.begin(), z.begin() + need);
        cout << z[(need - 1) / 2] << "\n";

    }
}

// x
// abs(x - a[i]) / k четно -- горит, иначе -- нет
// abs(x - a[1]) < k (mod 2k)
// abs(x - a[2]) < k (mod 2k)