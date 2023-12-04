#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll gcd = __gcd(b, d);
    ll lcm = (b / gcd) * d;
    a *= lcm / b;
    c *= lcm / d;
    ll p = a + c;
    ll q = lcm;
    ll norm = __gcd(p, q);
    p /= norm;
    q /= norm;
    cout << p << ' ' << q;
    return 0;
}

/**


**/
