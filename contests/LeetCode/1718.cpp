#include <functional>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> answer = {
        {1},
        {2, 1, 2},
        {3, 1, 2, 3, 2},
        {4, 2, 3, 2, 4, 3, 1},
        {5, 3, 1, 4, 3, 5, 2, 4, 2},
        {6, 4, 2, 5, 2, 4, 6, 3, 5, 1, 3},
        {7, 5, 3, 6, 4, 3, 5, 7, 4, 6, 2, 1, 2},
        {8, 6, 4, 2, 7, 2, 4, 6, 8, 5, 3, 7, 1, 3, 5},
        {9, 7, 5, 3, 8, 6, 3, 5, 7, 9, 4, 6, 8, 2, 4, 2, 1},
        {10, 8, 6, 9, 3, 1, 7, 3, 6, 8, 10, 5, 9, 7, 4, 2, 5, 2, 4},
        {11, 9, 10, 6, 4, 1, 7, 8, 4, 6, 9, 11, 10, 7, 5, 8, 2, 3, 2, 5, 3},
        {12, 10, 11, 7, 5, 3, 8, 9, 3, 5, 7, 10, 12, 11, 8, 6, 9, 2, 4, 2, 1, 6, 4},
        {13, 11, 12, 8, 6, 4, 9, 10, 1, 4, 6, 8, 11, 13, 12, 9, 7, 10, 3, 5, 2, 3, 2, 7, 5},
        {14, 12, 13, 9, 7, 11, 4, 1, 10, 8, 4, 7, 9, 12, 14, 13, 11, 8, 10, 6, 3, 5, 2, 3, 2, 6, 5},
        {15, 13, 14, 10, 8, 12, 5, 3, 11, 9, 3, 5, 8, 10, 13, 15, 14, 12, 9, 11, 7, 4, 6, 1, 2, 4, 2, 7, 6},
        {16, 14, 15, 11, 9, 13, 6, 4, 12, 10, 1, 4, 6, 9, 11, 14, 16, 15, 13, 10, 12, 8, 5, 7, 2, 3, 2, 5, 3, 8, 7},
        {17, 15, 16, 12, 10, 14, 7, 5, 3, 13, 11, 3, 5, 7, 10, 12, 15, 17, 16, 14, 9, 11, 13, 8, 6, 2, 1, 2, 4, 9, 6, 8, 4},
        {18, 16, 17, 13, 11, 15, 8, 14, 4, 2, 12, 2, 4, 10, 8, 11, 13, 16, 18, 17, 15, 14, 12, 10, 9, 7, 5, 3, 6, 1, 3, 5, 7, 9, 6},
        {19, 17, 18, 14, 12, 16, 9, 15, 6, 3, 13, 1, 3, 11, 6, 9, 12, 14, 17, 19, 18, 16, 15, 13, 11, 10, 8, 4, 5, 7, 2, 4, 2, 5, 8, 10, 7},
        {20, 18, 19, 15, 13, 17, 10, 16, 7, 5, 3, 14, 12, 3, 5, 7, 10, 13, 15, 18, 20, 19, 17, 16, 12, 14, 11, 9, 4, 6, 8, 2, 4, 2, 1, 6, 9, 11, 8}
    };
    std::vector<int> constructDistancedSequence(int n) {
        return answer[n - 1];
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    for (int n = 1; n < 20; ++n) {
        int m = (n << 1) - 1;
        std::vector<int> result(m);
        std::vector<bool> used(n, false);
        used[0] = true;
        std::vector<std::vector<int>> answers;
        std::function<void(int, int)> put = [&](int position, int value) {
            if (!answers.empty()) return;
            if (!(0 <= position && position < m) || result[position] != 0 || m <= position + value + 1 || result[position + value + 1] != 0) return;
            used[value] = true;
            result[position] = value;
            result[position + value + 1] = value;
            bool allUsed = true;
            for (bool variable : used) {
                allUsed &= variable;
            }
            if (allUsed) {
                answers.push_back(result);
            }
            for (int j = 0; j < m; ++j) {
                if (result[j] != 0) continue;
                for (int i = n - 1; i >= 0; --i) {
                    if (used[i]) continue;
                    put(j, i);
                }
            }
            used[value] = false;
            result[position] = 0;
            result[position + value + 1] = 0;
        };
        put(0, n - 1);
        for (const auto& i : answers) {
            for (const auto& j : i) {
                std::cout << j + 1 << " ";
            }
            std::cout << std::endl;
        }
    }
    // std::sort(answers.begin(), answers.end(), 
    //     [&](const std::vector<int>& lhs, const std::vector<int>& rhs){
    //         for (int i = 0; i < m; ++i) {
    //             if (lhs[i] != rhs[i]) return lhs[i] > rhs[i];
    //         }
    //         return false;
    //     });
    // for (const auto& i : answers[0]) {
    //     std::cout << i + 1 << " ";
    // }
    return 0;
}

/**

1
2 1 2
3 1 2 3 2
4 2 3 2 4 3 1

**/
