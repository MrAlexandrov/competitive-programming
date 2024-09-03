#include <bits/stdc++.h>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int x, y, k;
        cin >> x >> y >> k;
        int ans_x = (x + k - 1) / k;
        int ans_y = (y + k - 1) / k;
        if (ans_x > ans_y) {
            ans_y = ans_x - 1;
        } else {
            ans_x = ans_y;
        }
        cout << ans_x + ans_y << endl;
    }
    return 0;
}

/**



**/