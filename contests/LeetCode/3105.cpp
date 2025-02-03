#include <iostream>
#include <vector>

class Solution {
public:
    int longestMonotonicSubarray(std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int result = 1;
        int longestIncreasingSubarray = 1;
        int longestDecreasingSubarray = 1;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                longestIncreasingSubarray = 1;
                longestDecreasingSubarray = 1;
            }
            if (nums[i] < nums[i + 1]) {
                ++longestIncreasingSubarray;
                longestDecreasingSubarray = 1;
                result = std::max(result, longestIncreasingSubarray);
            }
            if (nums[i] > nums[i + 1]) {
                ++longestDecreasingSubarray;
                longestIncreasingSubarray = 1;
                result = std::max(result, longestDecreasingSubarray);
            }
        }
        return result;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    
    return 0;
}

/**



**/
