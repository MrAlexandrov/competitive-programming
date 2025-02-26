#include <algorithm>
#include <iostream>
#include <numeric>
#include <ostream>
#include <vector>

class Solution {
public:
    int maxAbsoluteSum(std::vector<int>& nums) {
        std::partial_sum(nums.begin(), nums.end(), nums.begin());
        return (
            std::max(0, *std::max_element(nums.begin(), nums.end()))
            - std::min(0, *std::min_element(nums.begin(), nums.end()))
        );
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n = 0;
    std::cin >> n;
    std::vector<int> nums(n);
    for (auto& i : nums) {
        std::cin >> i;
    }
    Solution solve;
    std::cout << solve.maxAbsoluteSum(nums);
    return 0;
}

/**



**/
