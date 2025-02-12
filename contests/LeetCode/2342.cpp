#include <cctype>
#include <iostream>
#include <optional>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <algorithm>

class Solution {
public:
    int SumDigits(int n) const {
        int result = 0;
        std::string text = std::to_string(n);
        for (const auto& c : text) {
            if (std::isdigit(c)) {
                result += (c - '0');
            }
        }
        return result;
    }

    int maximumSum(std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        std::unordered_map<int, std::pair<std::optional<int>, std::optional<int>>> sumOfPairs;
        auto insert = [&](int k) {
            int sum = SumDigits(k);
            auto& element = sumOfPairs[sum];
            if (!element.first.has_value()) {
                element.first = k;
                return;
            }
            if (!element.second.has_value()) {
                if (k < element.first) {
                    element.second = element.first;
                    element.first = k;
                } else {
                    element.second = k;
                }
                return;
            }
            if (k < element.first) return;
            if (k < element.second) {
                element.first = k;
                return;
            }
            element.first = element.second;
            element.second = k;
        };
        for (const auto& i : nums) {
            insert(i);
        }
        std::optional<int> answer = std::nullopt;
        for (const auto& i : sumOfPairs) {
            if (!i.second.first.has_value() || !i.second.second.has_value()) {
                continue;
            }
            int newSum = i.second.first.value() + i.second.second.value();
            if (!answer.has_value()) {
                answer = newSum;
            } else {
                answer = std::max(answer.value(), newSum);
            }
        }
        return answer.value_or(-1);
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
    std::cout << solve.maximumSum(nums);
    return 0;
}

/**



**/
