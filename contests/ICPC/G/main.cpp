#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ull x;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int k;
    cin >> k;
    cin >> x;
    bool negative = x & (1ULL << 63);

    ull mant = 0;
    ull por = 0;

    for (int i = 0; i < k; ++i) {
        mant += (x & (1ULL << i));
    }

    for (int i = k; i < 63; ++i) {
        por += ((x & (1ULL << i)) >> k);
    }

    ull bad_p = (1ULL << (63 - k)) - 1;

    if (por = bad_p) {
        cout << "NaN";
        return 0;
    }


    return 0;
}

/**


**/
