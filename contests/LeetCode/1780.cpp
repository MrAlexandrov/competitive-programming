#include "utils.h"

#include <iostream>

class Solution {
public:
    bool checkPowersOfThree(int n) const {
        int value = 1;
        while (value <= n) {
            value *= 3;
        }
        value /= 3;
        while (value > 0) {
            if (value <= n) {
                n -= value;
            }
            value /= 3;
        }
        return n == 0;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n = 0;
    std::cin >> n;
    Solution solve;
    std::cout << solve.checkPowersOfThree(n);
    return 0;
}

/**



**/
