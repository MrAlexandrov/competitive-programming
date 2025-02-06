#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int maxOperations(std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int m = n;
        if (m & 1) {
            --m;
        }
        int sum = -1;
        int answer = 0;
        for (int i = 0; i < m; i += 2) {
            if (sum == -1) {
                sum = nums[i] + nums[i + 1];
            }
            if (nums[i] + nums[i + 1] == sum) {
                ++answer;
            } else {
                return answer;
            }
        }
        return answer;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (auto& i : nums) {
        std::cin >> i;
    }
    Solution solve;
    std::cout << solve.maxOperations(nums);
    return 0;
}

/**



**/
