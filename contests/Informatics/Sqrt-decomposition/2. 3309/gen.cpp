#include <bits/stdc++.h>
using namespace std;

mt19937 rnd(time(0));

int main() {
	int n = rnd() % 1000 + 1;
	cout << n << '\n';
	for (int i = 0; i < n; ++i) {
		cout << rnd() % 1000 + 1 << ' ';
	}
	cout << '\n';
	int k = rnd() % 1000;
	cout << k << '\n';
	for (int i = 0; i < k; ++i) {
		int l = rnd() % n + 1, r = rnd() % n + 1;
		if (l > r) swap(l, r);
		cout << l << ' ' << r << '\n';
	}
	return 0;
}
