#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector <int> cnt(4, 0);
        int result = 0;
        for (char i : s) {
            if (i == '?') {
                // ++result;
            } else {
                ++cnt[i - 'A'];
            }
        }
        for (int i = 0; i < 4; ++i) {
            cnt[i] = (cnt[i] > n ? n : cnt[i]);
            result += cnt[i];
        }
        cout << result << '\n';
    }
    return 0;
}