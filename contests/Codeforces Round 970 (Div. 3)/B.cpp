#include <bits/stdc++.h>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int sqrt_ = sqrt(n);
        if (sqrt_ * sqrt_ != n) {
            cout << "No" << endl;
            continue;
        }

        bool ok = true;
        for (int i = 0; i < sqrt_; ++i) {
            for (int j = 0; j < sqrt_; ++j) {
                auto& current_element = s[i * sqrt_ + j];  

                if (j == 0 || j == sqrt_ - 1) {
                    ok &= current_element == '1';
                    continue;
                }

                if (i == 0 || i == sqrt_ - 1) {
                    ok &= current_element == '1';
                    continue;
                }

                ok &= current_element == '0';
            }
        }

        cout << (ok ? "Yes" : "No") << endl;
    }
    return 0;
}

/**



**/