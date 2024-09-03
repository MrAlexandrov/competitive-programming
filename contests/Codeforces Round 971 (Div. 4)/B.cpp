#include <bits/stdc++.h>
#include <vector>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < 4; ++j) {
                if (s[j] == '#') {
                    ans[n - i - 1] = j + 1;
                }
            }
        }
        for (auto& i : ans) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}

/**



**/