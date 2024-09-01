#include <bits/stdc++.h>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int a_mod = a % 2;
        int b_mod = b % 2;

        if (a_mod == 0 && b_mod == 0) {
            cout << "YES" << endl;
            continue;
        }

        if (a_mod == 0 && b_mod == 1 && a > 0) {
            cout << "YES" << endl;
            continue;
        }

        if (a_mod == 1) {
            cout << "NO" << endl;
            continue;
        }

        cout << "NO" << endl;
        continue;
    }
    return 0;
}

/**



**/