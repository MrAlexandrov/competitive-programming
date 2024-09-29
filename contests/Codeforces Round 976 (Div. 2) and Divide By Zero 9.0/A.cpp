#include <bits/stdc++.h>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        long long n, k;
        cin >> n >> k;

        if (k == 1) {
            cout << n << '\n';
            continue;
        }

        long long sub = k;
        while (sub * k <= n) {
            sub *= k;
        }
        long long result = 0;
        while (n > 0) {
            result += (n / sub);
            n %= sub;
            sub /= k;
        }
        cout << result << '\n';
    }
    cout << endl;
    return 0;
}

/**



**/