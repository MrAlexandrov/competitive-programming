#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll binpow(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1) {
			res *= a;
		}
		a *= a;
		n >>= 1;
	}
	return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector <ll> a(m);
    vector <int> ind(m);
    ll sum = 0;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        ind[i] = i;
        sum += a[i];
    }
    sum <<= 1;
    sort(ind.begin(), ind.end(), [&](int i, int j) {
        return a[i] > a[j];
    });
    /*for (int i : ind) {
        cout << i << ' ';
    }
    return 0;*/
    if (sum < n) {
        cout << "-1";
        return 0;
    }
    int perebor = binpow(3, m);
    int ans = -1;
    int bricks = 100;
    for (int i = 0; i < perebor; ++i) {
        ll now = i;
        ll current_sum = 0;
        int cnt = 0;
        for (int j = 0; j < m; ++j) {
            current_sum += a[ind[j]] * (now % 3);
            cnt += (now % 3);
            now /= 3;
            if (current_sum > n) {
                break;
            }
        }
        if (current_sum == n) {
            if (cnt < bricks) {
                ans = i;
                bricks = cnt;
            }
        }
    }
    if (ans == -1) {
        cout << "0";
        return 0;
    }
    cout << bricks << '\n';
    for (int i = 0; i < m; ++i) {
        ll now = ans % 3;
        for (int j = 0; j < now; ++j) {
            cout << a[ind[i]] << ' ';
        }
        ans /= 3;
    }
    return 0;
}

/**


**/
