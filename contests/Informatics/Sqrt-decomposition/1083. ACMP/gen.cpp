#include <bits/stdc++.h>
using namespace std;

mt19937 rnd(time(0));

int main() {
	int MAXN = 1000;
	int n = rnd() % MAXN + 1;
	cout << n << '\n';
	for (int i = 0; i < n; ++i) {
		cout << rnd() % MAXN + 1 << ' ';
	}
	cout << '\n';
	int m = rnd() % MAXN;
	cout << m << '\n';
	vector <string> operation = {"rsq", "update", "rmq", "add", "get"};
	vector <int> cnt = {2, 3, 2, 3, 1};
	for (int i = 0; i < m; ++i) {
		int number = rnd() % 5;
		cout << operation[number] << ' ';
		vector <int> nums(3);
		nums[0] = rnd() % n + 1;
		nums[1] = rnd() % n + 1;
		nums[2] = rnd() % MAXN + 1;
		if (nums[1] < nums[0]) swap(nums[1], nums[0]);
		for (int j = 0; j < cnt[number]; ++j) {
			cout << nums[j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
