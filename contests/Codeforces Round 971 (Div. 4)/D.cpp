#include <bits/stdc++.h>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <vector <int>> a(n + 1, vector<int>(2, 0));
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            a[x][y] = 1;
        }
        long long cnt_up = 0, cnt_down = 0, cnt_both = 0;

        for (int i = 0; i <= n; ++i) {
            if (a[i][0] == 1 && a[i][1] == 1) {
                ++cnt_both;
                continue;
            }
            cnt_up += (a[i][1] == 1);
            cnt_down += (a[i][0] == 1);
        }

        long long answer = 0;
        answer += cnt_both * (cnt_up + cnt_down);
        answer += cnt_both * (cnt_both - 1) * 2; // (4 * ()) / 2

        for (int i = 1; i < n; ++i) {
            answer += (a[i - 1][0] == 1 && a[i][1] == 1 && a[i + 1][0] == 1);
            answer += (a[i - 1][1] == 1 && a[i][0] == 1 && a[i + 1][1] == 1);
        }

        cout << answer << endl;
    }
    return 0;
}

/**



**/