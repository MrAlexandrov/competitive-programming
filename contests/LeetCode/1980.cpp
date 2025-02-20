#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string findDifferentBinaryString(std::vector<std::string>& nums) {
        int n = static_cast<int>(nums.size());
        std::string result(n, '0');
        for (int i = 0; i < n; ++i) {
            result[i] = ('1' - nums[i][i]) + '0';
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
