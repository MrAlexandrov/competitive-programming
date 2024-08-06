#include <bits/stdc++.h>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        int result = 0;
        auto calc = [&]() {
            return (a1 > b1 && a2 > b2) || (a1 > b1 && a2 == b2) || (a1 == b1 && a2 > b2);
        };
        result += calc();
        swap(b1, b2);
        result += calc();
        
        swap(a1, a2);
        result += calc();
        swap(b1, b2);
        result += calc();
        cout << result << '\n';
    }
    return 0;
}

/*


*/