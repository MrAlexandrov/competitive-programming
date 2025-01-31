#include <algorithm>
#include <functional>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int largestIsland(std::vector<std::vector<int>>& grid) {
        int n = static_cast<int>(grid.size());
        int m = static_cast<int>(grid.front().size());

        std::vector<std::vector<int>> color(n, std::vector<int>(m));
        std::vector<int> sizeOfColor{0};

        auto isOk = [&](int x, int y) -> bool {
            return (0 <= x && x < n && 0 <= y && y < m && grid[x][y] == 1);
        };

        std::vector<int> dx = {-1, 0, 1, 0};
        std::vector<int> dy = {0, -1, 0, 1};

        std::function<void(int, int, int)> fillColorAndSize = [&](int x, int y, int currentColor) {
            color[x][y] = currentColor;
            ++sizeOfColor[currentColor];

            for (int step = 0; step < 4; ++step) {
                int newX = x + dx[step];
                int newY = y + dy[step];
                if (!isOk(newX, newY) || color[newX][newY] != 0) continue;
                fillColorAndSize(newX, newY, currentColor);
            }
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0 || color[i][j] != 0) continue;
                sizeOfColor.push_back(0);
                fillColorAndSize(i, j, static_cast<int>(sizeOfColor.size() - 1));
            }
        }

        int answer = *std::max_element(sizeOfColor.begin(), sizeOfColor.end());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) continue;
                int currentAnswer = 1;
                std::set<int> unitedColors;
                for (int step = 0; step < 4; ++step) {
                    int newX = i + dx[step];
                    int newY = j + dy[step];
                    if (!isOk(newX, newY)) continue;
                    unitedColors.insert(color[newX][newY]);
                }
                for (const auto& currentColor : unitedColors) {
                    currentAnswer += sizeOfColor[currentColor];
                }
                answer = std::max(answer, currentAnswer);
            }
        }

        return answer;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    int n;
    cin >> n;
    std::vector<std::vector<int>> grid(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> grid[i][j];
        }
    }
    Solution local;
    std::cout << local.largestIsland(grid);
    return 0;
}

/**



**/