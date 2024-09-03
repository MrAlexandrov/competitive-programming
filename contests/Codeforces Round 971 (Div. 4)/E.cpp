#include <bits/stdc++.h>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        auto check = [&n, &k](long long m) {
            long long add = k * m + (m - 1) * m / 2;
            long long sub = k * (n - m) + (m + (n - 1)) * (n - m) / 2;
            return abs(add - sub);
        };

        long long answer = check(0);

        long long l = 1, r = n - 1;
        
        while (r - l > 2) {
            long long ml = (l + l + r) / 3;
            long long mr = (l + r + r) / 3;

            long long left = check(ml);
            long long right = check(mr); 


            if (left == right) {
                l = ml;
                r = mr;
            } else {
                if (left < right) {
                    r = mr;
                } else {
                    l = ml;
                }
            }
        }

        for (long long i = l; i <= r; ++i) {
            answer = min(answer, check(i));
        }

        cout << answer << endl;
    }
    return 0;
}

/**

2 3 4 5 6 7 8

**/