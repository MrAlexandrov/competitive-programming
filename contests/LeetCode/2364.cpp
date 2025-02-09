#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    long long countBadPairs(std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        long long answer = 0;
        std::unordered_map<int, int> countDifference;
        for (int i = 0; i < n; ++i) {
            ++countDifference[nums[i] - i];
        }
        for (const auto& i : countDifference) {
            answer += (n - i.second) * i.second;
        }
        answer >>= 1;
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
    std::cout << solve.countBadPairs(nums);
    return 0;
}

/**



**/
