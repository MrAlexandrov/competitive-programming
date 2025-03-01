#include <iostream>
#include <ostream>
#include <sstream>
#include <vector>

class Solution {
public:
    std::vector<int> applyOperations(std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] <<= 1;
                nums[i + 1] = 0;
            }
        }
        std::vector<int> result;
        result.reserve(n);
        for (const auto& i : nums) {
            if (i != 0) {
                result.push_back(i);
            }
        }
        result.resize(n, 0);
        return result;
    }
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& value) {
    for (const auto& i : value) {
        out << i << " ";
    }
    return out;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::string s;
    getline(std::cin, s);
    std::stringstream ss(s);
    std::vector<int> nums;
    int x = 0;
    while (ss >> x) {
        nums.push_back(x);
    }
    Solution solve;
    std::cout << solve.applyOperations(nums);
    return 0;
}

/**



**/
