#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> odd;
        vector <int> even;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (x & 1) {
                odd.push_back(x);
            } else {
                even.push_back(x);
            }
        }
        if (odd.size() == 0 || even.size() == 0) {
            cout << 0 << '\n';
            continue;
        }
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        int answer = 0;
        long long current_element = odd.back();
        int ptr = 0;
        bool bad = false;
        while (ptr < even.size()) {
            #ifdef DEBUG
            cout << "before " << current_element << ' ' << even[ptr] << endl;
            #endif // DEBUG
            if (even[ptr] < current_element) {
                current_element += even[ptr];
            } else {
                bad = true;
            }
            #ifdef DEBUG
            cout << "after " << current_element << ' ' << even[ptr] << endl;
            #endif // DEBUG
            ++ptr;
        }
        answer = even.size();
        answer += bad;
        cout << answer << '\n';
    }
    return 0;
}