#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int numTilePossibilities(std::string tiles) {
        int n = static_cast<int>(tiles.size());
        std::vector<std::string> answer;
        for (int i = 1, end = (1 << n); i < end; ++i) {
            std::string currentAnswer;
            for (int j = 0; j < n; ++j) {
                if ((1 << j) & i) {
                    currentAnswer += tiles[j];
                }
            }
            std::sort(currentAnswer.begin(), currentAnswer.end());
            do {
                answer.push_back(currentAnswer);
            } while (std::next_permutation(currentAnswer.begin(), currentAnswer.end()));
        }
        std::sort(answer.begin(), answer.end());
        answer.erase(std::unique(answer.begin(), answer.end()), answer.end());
        return static_cast<int>(answer.size());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::string tiles;
    std::cin >> tiles;
    Solution solve;
    std::cout << solve.numTilePossibilities(tiles);
    return 0;
}

/**



**/
