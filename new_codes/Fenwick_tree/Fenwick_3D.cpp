#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 7;

struct Fenwick {
	int n, m, h;
	vector <vector <vector <ll>>> t;
	Fenwick () {}
	Fenwick (int _n, int _m, int _h) : n(_n), m(_m), h(_h) {
		t.resize(n);
		for (int i = 0; i < n; ++i) {
			t[i].resize(m);
			for (int j = 0; j < m; ++j) {
				t[i][j].resize(h, 0);
			}
		}
	}
	Fenwick (const vector <vector <vector <int>>>& a) {
		n = (int)a.size();
		m = (int)a[0].size();
		h = (int)a[0][0].size();
		t.resize(n);
		for (int i = 0; i < n; ++i) {
			t[i].resize(m);
			for (int j = 0; j < m; ++j) {
				t[i][j].resize(h, 0);
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				for (int k = 0; k < h; ++k) {
					t[i][j][k] = a[i][j][k];
					if (!i && !j && !k) continue;
					
					if (i) t[i][j][k] += t[i - 1][j][k];
					if (j) t[i][j][k] += t[i][j - 1][k];
					if (k) t[i][j][k] += t[i][j][k - 1];
					
					if (i && j) t[i][j][k] -= t[i - 1][j - 1][k];
					if (i && k) t[i][j][k] -= t[i - 1][j][k - 1];
					if (j && k) t[i][j][k] -= t[i][j - 1][k - 1];
					
					if (i && j && k) t[i][j][k] += t[i - 1][j - 1][k - 1];
				}
			}
		}
		for (int rx = n - 1; rx >= 0; --rx) {
			for (int ry = m - 1; ry >= 0; --ry) {
				for (int rz = h - 1; rz >= 0; --rz) {
					int lx = rx & (rx + 1);
					int ly = ry & (ry + 1);
					int lz = rz & (rz + 1);
					if (!lx && !ly && !lz) continue;
					if (lx) t[rx][ry][rz] -= t[lx - 1][ry][rz];
					if (ly) t[rx][ry][rz] -= t[rx][ly - 1][rz];
					if (lz) t[rx][ry][rz] -= t[rx][ry][lz - 1];
					
					if (lx && ly) t[rx][ry][rz] += t[lx - 1][ly - 1][rz];
					if (lx && lz) t[rx][ry][rz] += t[lx - 1][ry][lz - 1];
					if (ly && lz) t[rx][ry][rz] += t[rx][ly - 1][lz - 1];
					
					if (lx && ly && lz) t[rx][ry][rz] -= t[lx - 1][ly - 1][lz - 1];
				}
			}
		}
	}
	void add(int x, int y, int z, ll val) {
		for (int i = x; i < n; i |= i + 1) {
			for (int j = y; j < m; j |= j + 1) {
				for (int k = z; k < h; k |= k + 1) {
					t[i][j][k] += val;
				}
			}
		}
	}
	ll pref(int x, int y, int z) {
		ll res = 0;
		for (int i = x; i >= 0; i &= i + 1, --i) {
			for (int j = y; j >= 0; j &= j + 1, --j) {
				for (int k = z; k >= 0; k &= k + 1, --k) {
					res += t[i][j][k];
				}
			}
		}
		return res;
	}
	ll sum(int lx, int ly, int lz, int rx, int ry, int rz) {
		return pref(rx, ry, rz) - 
			  (pref(lx - 1, ry, rz) + pref(rx, ly - 1, rz) + pref(rx, ry, lz - 1)) +
			  (pref(lx - 1, ly - 1, rz) + pref(lx - 1, ry, lz - 1) + pref(rx, ly - 1, lz - 1)) -
			  (pref(lx - 1, ly - 1, lz - 1));
	}
/**
(0,0)-------------------------------*
  |      (lx, ly)-----------*		|
  |			|				|		|
  | 		*-----------(rx, ry)	|
  |									|
  *-------------------------------(n, m)
**/
	void upd(int x, int y, int z, ll val) {
		ll delta = val - sum(x, y, z, x - 1, y - 1, z - 1);
		add(x, y, z, delta);
	}
	void viv() {
		cout << "viv " << endl;
		for (int k = 0; k < h; ++k) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					cout << t[i][j][k] << ' ';
				}
				cout << endl;
			}
			cout << endl;
		}
		cout << endl;
	}
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("stars.in", "r", stdin);
    ///freopen("stars.out", "w", stdout);
	int n;
	cin >> n;
	Fenwick T(n, n, n);
	while (true) {
		int t;
		cin >> t;
		if (t == 3) break;
		if (t == 2) {
			int x1, x2, y1, y2, z1, z2;
			cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
			if (x1 > x2) swap(x1, x2);
			if (y1 > y2) swap(y1, y2);
			if (z1 > z2) swap(z1, z2);
			cout << T.sum(x1, y1, z1, x2, y2, z2) << '\n';	
		} else {
			int x, y, z;
			cin >> x >> y >> z;
			int val;
			cin >> val;
			T.add(x, y, z, val);
		}
	}
	return 0;
}

/**
https://codeforces.com/gym/100246 // B
2
2 1 1 1 1 1 1
1 0 0 0 1
1 0 1 0 3
2 0 0 0 0 0 0
2 0 0 0 0 1 0
1 0 1 0 -2
2 0 0 0 1 1 1
3

**/