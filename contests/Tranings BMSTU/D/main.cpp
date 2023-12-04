#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll romanToDecimal(string roman) {
    unordered_map <char, int> romanMap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    ll decimal = 0;
    ll prevValue = 0;

    for (int i = roman.size() - 1; i >= 0; i--) {
        int curValue = romanMap[roman[i]];
        if (curValue < prevValue) {
            decimal -= curValue;
        } else {
            decimal += curValue;
        }
        prevValue = curValue;
    }
    return decimal;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    string a, b;
    cin >> a >> b;
    ll aa = romanToDecimal(a), bb = romanToDecimal(b);
    if (aa == bb) {
        cout << 0;
    } else {
        cout << (aa < bb ? -1 : 1);
    }
    return 0;
}

/**


**/
