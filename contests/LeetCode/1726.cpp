#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int tupleSameProduct(std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        std::vector<int> products;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                products.push_back(nums[i] * nums[j]);
            }
        }
        long long answer = 0;
        std::sort(products.begin(), products.end());
        int currentSize = 1;
        int m = static_cast<int>(products.size());
        for (int i = 0; i < m - 1; ++i) {
            if (products[i] == products[i + 1]) {
                ++currentSize;
            } else {
                answer += currentSize * (currentSize - 1);
                currentSize = 1;
            }
        }
        answer += currentSize * (currentSize - 1);
        answer <<= 2;
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
    std::cout << solve.tupleSameProduct(nums);
    return 0;
}

/**



**/
