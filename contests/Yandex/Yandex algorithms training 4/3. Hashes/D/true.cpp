#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int n, m;
	cin >> n >> m;
	vector <int> s(n);
	for (int &i : s) {
		cin >> i;
	}
	for (int i = 0; i < n; ++i) {
		vector <int> now(i + 1);
		for (int j = 0; j < i + 1; ++j) {
			now[j] = s[j];
		}
		for (int j = i; j >= 0; --j) {
			now.push_back(s[j]);
		}
		bool ok = true;
		if (now.size() < n) {
			ok = false;
		}
		for (int j = now.size() - n; j < now.size() && ok; ++j) {
			if (now[j] != s[j - (now.size() - n)]) {
				ok = false;
			}
		}
		if (ok) {
			cout << i + 1 << ' ';
		}
	}
    return 0;
}

/**


**/
