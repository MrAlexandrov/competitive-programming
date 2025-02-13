#include <functional>
#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        int answer = 0;
        std::priority_queue<long long, std::vector<long long>, std::greater<long long>> values{nums.begin(), nums.end()};
        while (values.size() > 1 && values.top() < k) {
            int minimum = values.top();
            values.pop();
            int secondMinimum = values.top();
            values.pop();
            values.emplace(static_cast<long long>(minimum) + minimum + secondMinimum);
            ++answer;
        }
        return answer;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> nums(n);
    for (auto& i : nums) {
        std::cin >> i;
    }
    Solution solve;
    std::cout << solve.minOperations(nums, k);
    return 0;
}

/**



**/
