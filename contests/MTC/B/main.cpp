#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const ld EPS = 1e-9;

vector <int> continuedFraction (ld x, int iter = 10) {
    vector <int> res;
    int integerPart = static_cast<int>(x);
    ld fractionalPart = x - integerPart;

    res.push_back(integerPart);

    for (int i = 0; i < iter; ++i) {
        if (fractionalPart < EPS) {
            break;
        }
        integerPart = static_cast<int>(1.0 / fractionalPart);
        fractionalPart = 1.0 / fractionalPart - integerPart;
        res.push_back(integerPart);
    }

    return res;
}

pair <int, int> continuedFractionToFraction(const vector <int> &cf) {
    int n = cf.size();
    int num = 1;
    int den = cf[n - 1];

    for (int i = n - 2; i >= 0; --i) {
        int temp = num;
        num = den;
        den = cf[i] * den + temp;
    }

    return {den, num};
}

void solve() {
    ld x;
    cin >> x;
    for (int i = 1; i < 11; ++i) {
        vector <int> frac = continuedFraction(x, i);
        int p = 0, q = 1;
        tie(p, q) = continuedFractionToFraction(frac);
        ld fin = (ld)p / q;
        fin = (ld)(((int)(fin * 100)) / 100.0);
        //cout << i << ' ' << (ld)p / q << ' ' << p << ' ' << q << ' ' << fin << endl;
        if (fabs(x - fin) < EPS) {
            cout << p << ' ' << q << endl;
            return;
        }
    }
    vector <int> frac = continuedFraction(x);
    int p = 0, q = 1;
    pair <int, int> temp = continuedFractionToFraction(frac);
    p = temp.first, q = temp.second;
    cout << p << ' ' << q << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/**


**/
