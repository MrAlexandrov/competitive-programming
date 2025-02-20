#include <bitset>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string findDifferentBinaryString(std::vector<std::string>& nums) {
        int n = static_cast<int>(nums.front().size());
        for (const auto& num : nums) {
            int currentNumber = 0;
            for (const auto& c : num) {
                currentNumber <<= 1;
                if (c == '1') ++currentNumber;
            }
            exists[currentNumber] = true;
        }
        std::string answer(n, '0');
        for (int i = 0, end = (1 << n); i < end; ++i) {
            if (!exists[i]) {
                int currentNumber = i;
                for (int j = n - 1; j >= 0; --j) {
                    if (currentNumber & 1) answer[j] = '1';
                    currentNumber >>= 1;
                }
                return answer;
            }
        }
        return {};
    }
private:
    std::bitset<(1 << 16)> exists;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::string> nums;
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        nums.push_back(s);
    }
    Solution solve;
    std::cout << solve.findDifferentBinaryString(nums);
    return 0;
}

/**



**/
