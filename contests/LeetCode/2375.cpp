#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string smallestNumber(std::string pattern) {
        int n = static_cast<int>(pattern.size());
        int value = 0;
        std::vector<std::pair<int, int>> position = {{value, 0}};
        for (int i = 0; i < n; ++i) {
            auto c = pattern[i];
            if (c == 'I') ++value;
            else --value;
            position.emplace_back(value, i + 1);
        }
        std::sort(position.begin(), position.end(), 
            [](const auto& lhs, const auto& rhs) {
                if (lhs.first + lhs.second == rhs.first + rhs.second) return lhs.first < rhs.first;
                return lhs.first + lhs.second < rhs.first + rhs.second;

                // if (lhs.second == rhs.second) return lhs.first < rhs.first;
                // else return lhs.second < rhs.second;

                // if (lhs.first == rhs.first) return lhs.second < rhs.second;
                // return lhs.first < rhs.first;
            }
        );
        // for (const auto& [val, pos] : position) {
        //     std::cout << val << " " << pos << std::endl;
        // }
        value = position.begin()->first;
        int mapping = 0;
        std::string result;
        result.resize(n + 1);
        for (const auto& [val, pos] : position) {
            result[pos] = static_cast<char>((++mapping) + static_cast<int>('0'));
        }
        return result;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::string pattern;
    std::cin >> pattern;
    Solution solve;
    std::cout << solve.smallestNumber(pattern);
    return 0;
}

/**

123549876

**/
