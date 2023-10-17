#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 7;

struct Fenwick {
	int n;
	vector <ll> t;
	Fenwick () {}
	Fenwick (int _n) : n(_n) {
		t.resize(n, 0);
	}
	Fenwick (const vector <ll>& a) {
		n = (int)a.size();
		t.resize(n, 0);
		ll sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += a[i];
			t[i] = sum;
		}
		for (int r = n - 1; r >= 0; --r) {
			int l = r & (r + 1);
			if (l == 0) continue;
			t[r] -= t[l - 1];
		}
	}
	void add(int i, ll val) {
		for (; i < n; i |= i + 1) {
			t[i] += val;
		}
	}
	ll pref(int i) {
		ll res = 0;
		for (; i >= 0; i &= i + 1, --i) {
			res += t[i];
		}
		return res;
	}
	ll sum(int l, int r) {
		return pref(r) - pref(l - 1);
	}
	void upd(int i, ll val) {
		ll delta = val - sum(i, i);
		add(i, delta);
	}
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector <ll> a(n);
	int m;
	cin >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	Fenwick T(a);
	while (m--) {
		int t;
		int l, r;
		cin >> t >> l >> r;
		if (!t) {
			cout << T.sum(l - 1, r - 1) << endl;
		} else {
			T.upd(l - 1, r);
		}
	}
	return 0;
}
