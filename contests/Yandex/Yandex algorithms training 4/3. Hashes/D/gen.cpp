#include <bits/stdc++.h>
using namespace std;

mt19937 rnd(time(0));

int main() {
	///freopen("test.txt", "r", stdin);
	int n = rnd() % 1000 + 1, m = rnd() % 1000 + 1;
	cout << n << ' ' << m << '\n';
	for (int i = 0; i < n; ++i) {
		cout << rnd() % m + 1 << ' ';
	}
	return 0;
}
