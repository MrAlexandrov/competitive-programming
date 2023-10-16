#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    vector <ld> r(3);
    cout << "? " << 0 << endl;
    cin >> r[0];
    cout << "? " << 120 << endl;
    cin >> r[1];
    cout << "? " << 240 << endl;
    cin >> r[2];

    ld a, b, c;
    a = sqrt(r[0] * r[0] + r[1] * r[1] + r[0] * r[1]);
    b = sqrt(r[0] * r[0] + r[2] * r[2] + r[0] * r[2]);
    c = sqrt(r[1] * r[1] + r[2] * r[2] + r[1] * r[2]);

    ld p = (a + b + c) / 2;

    ld R = (a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c)));

    cout << "! " << R << endl;
    return 0;
}

/**


**/
