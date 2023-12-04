#include <bits/stdc++.h>
using namespace std;

mt19937 rnd(time(0));

int main() {
	///freopen("test.txt", "r", stdin);
	int n = rnd() % 10;
	cout << n << '\n';
	int ind = rnd() % n;
	int el;
	for (int i = 0; i < n; ++i) {
		if (i == ind) {
			el = rnd() % 10;
			cout << el << ' ';
		} else {
			cout << rnd() % 10 << ' ';
		}
	}
	cout << '\n';
	cout << el;
	return 0;
}
