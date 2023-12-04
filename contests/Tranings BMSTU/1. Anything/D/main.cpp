#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int binpow(int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1) {
			res *= a;
		}
		a *= a;
		n >>= 1;
	}
	return res;
}

const int MAXN = binpow(2, 19) + 7;

int k, q;
int n;
string s;
vector <int> a(MAXN, 1);

void build(int v) {
    if (v >= n - 1) return;
    if (v >= (n - 1) - (n >> 1)) {
        if (s[v] == '?') {
            a[v] = 2;
        } else {
            a[v] = 1;
        }
        return;
    }
    build((v << 1) + 1);
    build((v << 1) + 2);
    if (s[v] == '?') {
        a[v] = a[(v << 1) + 1] + a[(v << 1) + 2];
    } else {
        a[v] = (s[v] == '1' ? a[(v << 1) + 1] : a[(v << 1) + 2]);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> k;
    cin >> s;
    //s += '&';
    reverse(s.begin(), s.end());
    n = 1 << k;
    build(0);
    cin >> q;
    while (q--) {
        int p;
        char c;
        cin >> p >> c;
        --p;
        p = (n - 1) - p - 1;
        int v = p;
        s[v] = c;
        do {
            if (s[v] == '?') {
                a[v] = a[(v << 1) + 1] + a[(v << 1) + 2];
            } else {
                a[v] = (s[v] == '1' ? a[(v << 1) + 1] : a[(v << 1) + 2]);
            }
            if (v == 0) break;
            --v;
            v >>= 1;
        } while (true);
        cout << a[0] << '\n';
    }
    return 0;
}

/**
3
0110?11
6
5 1
6 ?
7 ?
1 ?
5 ?
1 1

1
2
3
3
5
4

**/
