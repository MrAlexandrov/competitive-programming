#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<bool>>> res = {
    {
        {false, false},
        {true, true}
    },
    {
        {true, false},
        {true, false}
    }
};

int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        long long b, c, d;
        cin >> b >> c >> d;
        long long result = 0;
        for (long long bit = 1, k = 1; bit < 63; ++bit, k *= 2) {
            for (long long i = 0; i < 2; ++i) {
                if (res[i][bool(b & k)][bool(c & k)] == bool(d & k)) {
                    result |= (k * i);
                }
            }
        }
        if ((result | b) == d + (result & c)) {
            cout << result;
        } else {
            cout << -1;
        }
        cout << '\n';
    }
    return 0;
}

/**



**/