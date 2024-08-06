#include <bits/stdc++.h>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int l = 1, r = 999;
        auto check = [&]() {
            int tl = (l + l + r) / 3, tr = (l + r + r) / 3; 
            cout << "? " << tl << ' ' << tr << endl;
            int x;
            cin >> x;
            if (x == (tl * tr)) {
                l = tr;
            } else if (x == (tl * (tr + 1))) {
                l = tl;
                r = tr;
            } else if (x == ((tl + 1) * (tr + 1))) {
                r = tl;
            } else {
                assert(false);
            }
        };
        while (r - l > 1) {
            check();
        }
        cout << "! " << r << endl;
    }
    return 0;
}

/*


*/