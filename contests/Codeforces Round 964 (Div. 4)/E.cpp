#include <bits/stdc++.h>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        long long l, r;
        cin >> l >> r;
        long long answer = 0;
        long long copy_l = l;
        while (copy_l > 0) {
            copy_l /= 3;
            ++answer;
        }
        long long now = 1;
        // cout << now << ' ' << l << endl;
        while (now <= r) {
            long long left = max(now, l);
            answer += (r - left + 1);
            now *= 3;
        }
        cout << answer << '\n';
    }
    return 0;
}

/*
2 3 4
0 9 4
0 3 4
0 1 4
0 0 4
0 0 1
0 0 0

*/