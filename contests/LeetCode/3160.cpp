#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> queryResults(int limit, std::vector<std::vector<int>>& queries) {
        std::vector<int> result;
        std::unordered_map<int, int> ballColor;
        std::unordered_map<int, int> countColors;
        for (const auto& query : queries) {
            int x = query.front();
            int y = query.back();
            auto currentBall = ballColor.find(x);
            if (currentBall != ballColor.end()) {
                int currentColour = currentBall->second;
                auto currentNumberColors = countColors.find(currentColour);
                --(currentNumberColors->second);
                if (currentNumberColors->second == 0) {
                    countColors.erase(currentNumberColors);
                }
            }
            ballColor[x] = y;
            ++countColors[y];
            result.push_back(static_cast<int>(countColors.size()));
        }
        return result;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    int n;
    int m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> queries;
    for (int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;
        queries.push_back({x, y});
    }
    Solution solve;
    std::vector<int> result = solve.queryResults(n, queries);
    for (const auto& i : result) {
        std::cout << i << " ";
    }
    return 0;
}

/**



**/
