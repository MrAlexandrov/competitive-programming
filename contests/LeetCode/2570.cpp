#include "utils.h"

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> mergeArrays(std::vector<std::vector<int>>& nums1, std::vector<std::vector<int>>& nums2) {
        std::vector<std::vector<int>> result;
        size_t n = nums1.size();
        size_t m = nums2.size();
        result.reserve(std::max(n, m));
        size_t i = 0;
        size_t j = 0;
        while (i < n && j < m) {
            if (nums1[i][0] == nums2[j][0]) {
                result.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                ++i;
                ++j;
                continue;
            }
            if (nums1[i][0] < nums2[j][0]) {
                result.push_back(nums1[i]);
                ++i;
            } else {
                result.push_back(nums2[j]);
                ++j;
            }
        }
        while (i < n) {
            result.push_back(nums1[i]);
            ++i;
        }
        while (j < m) {
            result.push_back(nums2[j]);
            ++j;
        }
        return result;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n = 0;
    std::cin >> n;
    std::vector<std::vector<int>> nums1;
    nums1.reserve(n);
    for (int i = 0; i < n; ++i) {
        int id = 0;
        int val = 0;
        std::cin >> id >> val;
        nums1.push_back({id, val});
    }

    int m = 0;
    std::cin >> m;
    std::vector<std::vector<int>> nums2;
    nums2.reserve(m);
    for (int i = 0; i < m; ++i) {
        int id = 0;
        int val = 0;
        std::cin >> id >> val;
        nums2.push_back({id, val});
    }

    Solution solve;
    std::cout << solve.mergeArrays(nums1, nums2);
    return 0;
}

/**



**/
