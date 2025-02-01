#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isArraySpecial(std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] % 2 == nums[i + 1] % 2) {
                return false;
            }
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
