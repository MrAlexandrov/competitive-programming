#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int &i : a) {
		cin >> i;
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		int l, r;
		cin >> l >> r;
		--l;
		int res = 0;
		for (int j = l; j < r; ++j) {
			res = max(res, a[j]);
		}
		cout << res << ' ';
	}
}