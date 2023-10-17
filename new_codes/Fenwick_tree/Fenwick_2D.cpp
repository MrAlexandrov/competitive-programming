#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 7;

struct Fenwick {
	int n, m;
	vector <vector <ll>> t;
	Fenwick () {}
	Fenwick (int _n, int _m) : n(_n), m(_m) {
		t.resize(n);
		for (int i = 0; i < n; ++i) {
			t[i].resize(m, 0);
		}
	}
	Fenwick (const vector <vector <int>>& a) {
		n = (int)a.size();
		m = (int)a[0].size();
		t.resize(n);
		for (int i = 0; i < n; ++i) {
			t[i].resize(m, 0);
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				t[i][j] = a[i][j];
				if (!i && !j) continue;
				
				if (i) t[i][j] += t[i - 1][j];
				if (j) t[i][j] += t[i][j - 1];
				
				if (i && j) t[i][j] -= t[i - 1][j - 1];
			}
		}
		for (int rx = n - 1; rx >= 0; --rx) {
			for (int ry = m - 1; ry >= 0; --ry) {
				int lx = rx & (rx + 1);
				int ly = ry & (ry + 1);
				if (!lx && !ly) continue;
				
				if (lx) t[rx][ry] -= t[lx - 1][ry];
				if (ly) t[rx][ry] -= t[rx][ly - 1];
				
				if (lx && ly) t[rx][ry] += t[lx - 1][ly - 1];
			}
		}
	}
	void add(int x, int y, ll val) {
		for (int i = x; i < n; i |= i + 1) {
			for (int j = y; j < m; j |= j + 1) {
				t[i][j] += val;
			}
		}
	}
	ll pref(int x, int y) {
		ll res = 0;
		for (int i = x; i >= 0; i &= i + 1, --i) {
			for (int j = y; j >= 0; j &= j + 1, --j) {
				res += t[i][j];
			}
		}
		return res;
	}
	ll sum(int lx, int ly, int rx, int ry) {
		return pref(rx, ry) - pref(lx - 1, ry) - pref(rx, ly - 1) + pref(lx - 1, ly - 1);
	}
/**
(0,0)-------------------------------*
  |      (lx, ly)-----------*		|
  |			|				|		|
  | 		*-----------(rx, ry)	|
  |									|
  *-------------------------------(n, m)
**/
	void upd(int x, int y, ll val) {
		ll delta = val - sum(x, y, x - 1, y - 1);
		add(x, y, delta);
	}
	void viv() {
		cout << endl;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cout << t[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int n, m, q;
	cin >> n >> m >> q;
	vector <vector <int>> a(n, vector <int> (m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	Fenwick T(a);
	while (q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << T.sum(x1 - 1, y1 - 1, x2 - 1, y2 - 1) << endl;
	}
	return 0;
}

/**
https://acmp.ru/asp/do/index.asp?main=task&id_course=2&id_section=20&id_topic=46&id_problem=602
https://acmp.ru/asp/do/index.asp?main=task&id_course=2&id_section=20&id_topic=44&id_problem=291

**/