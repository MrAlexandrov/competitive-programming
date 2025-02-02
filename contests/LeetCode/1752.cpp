#include <iostream>
#include <optional>
#include <vector>

class Solution {
public:
    bool check(std::vector<int>& nums) {
        std::optional<int> startIndex = std::nullopt;
        int n = static_cast<int>(nums.size());
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                if (startIndex.has_value()) return false;
                startIndex = i + 1;
            }
        }
        if (!startIndex.has_value()) return true;
        for (int i = startIndex.value(), end = startIndex.value() + n - 1; i < end; ++i) {
            int l = nums[i % n];
            int r = nums[(i + 1) % n];
            if (l > r) return false;
        }
        return true;
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
