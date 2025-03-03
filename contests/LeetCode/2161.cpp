#include "utils.h"

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> pivotArray(std::vector<int>& nums, int pivot) {
        auto value = std::stable_partition(nums.begin(), nums.end(), [&pivot](int x){
            return x < pivot;
        });
        std::stable_partition(value, nums.end(), [&pivot](int x) {
            return x == pivot;
        });
        return nums;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::vector<int> nums;
    std::cin >> nums;
    int pivot = 0;
    std::cin >> pivot;
    Solution solve;
    std::cout << solve.pivotArray(nums, pivot);
    return 0;
}

/**



**/
