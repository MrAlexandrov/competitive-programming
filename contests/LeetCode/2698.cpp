#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<int> precalc{1, 9, 10, 36, 45, 55, 82, 91, 99, 100, 235, 297, 369, 370, 379, 414, 657, 675, 703, 756, 792, 909, 918, 945, 964, 990, 991, 999, 1000};
    int punishmentNumber(int n) {
        auto last = std::upper_bound(precalc.begin(), precalc.end(), n);
        int result = 0;
        for (auto i = precalc.begin(); i != last; ++i) {
            result += (*i) * (*i);
        }
        return result;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    Solution solve;
    std::cout << solve.punishmentNumber(n);
    return 0;
    auto partioned = [](int x) {
        int square = x * x;
        std::string str = std::to_string(square);
        int n = static_cast<int>(str.size());
        for (int mask = 0, end = (1 << (n - 1)); mask < end; ++mask) {
            int result = 0;
            std::string currentNumber{str[0]};
            for (int i = 0; i < n - 1; ++i) {
                if ((1 << i) & mask) {
                    result += std::stoi(currentNumber);
                    currentNumber = str[i + 1];
                } else {
                    currentNumber += str[i + 1];
                }
            }
            result += std::stoi(currentNumber);
            if (result == x) {
                std::cout << x << std::endl;
                break;
            }
        }
    };
    for (int i = 1; i <= 1000; ++i) {
        partioned(i);
    }
    return 0;
}

/**



**/
