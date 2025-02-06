#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int minNumberOfFrogs(std::string croakOfFrogs) {
        std::unordered_map<char, int> mapping = {
            {'c', 0},
            {'r', 1}, 
            {'o', 2},
            {'a', 3},
            {'k', 4},
        };
        std::vector<int> counter(5, 0);
        int answer = 0;
        for (const auto& i : croakOfFrogs) {
            int index = mapping[i];
            if (index == 0) {
                ++counter[index];
            } else {
                if (counter[index - 1] <= counter[index]) {
                    return -1;
                } else {
                    ++counter[index];
                }
                answer = std::max(
                    answer, 
                    *std::max_element(counter.begin(), counter.end())
                );
                if (index == 4) {
                    for (auto& j : counter) {
                        --j;
                    }
                }
            }
        }
        for (int i = 0; i < 4; ++i) {
            if (counter[i] != counter[i + 1]) return -1;
        }
        return answer;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    std::string croakOfFrogs;
    std::cin >> croakOfFrogs;
    Solution solve;
    std::cout << solve.minNumberOfFrogs(croakOfFrogs);
    return 0;
}

/**



**/
