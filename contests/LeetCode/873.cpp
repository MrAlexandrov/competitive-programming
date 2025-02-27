#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>

class Solution {
public:
    int lenLongestFibSubseq(std::vector<int>& arr) {
        int n = static_cast<int>(arr.size());
        std::unordered_map<int, std::vector<int>> position;
        for (int i = 0; i < n; ++i) {
            position[arr[i]].push_back(i);
        }
        int answer = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (arr[i] > arr[j]) {
                    continue;
                }
                int a = i;
                int b = j;
                int currentResult = 0;
                while (true) {
                    int value = arr[a] + arr[b];
                    if (!position.contains(value)) {
                        break;
                    }
                    const auto& currentPosition = position[value];
                    auto next = std::upper_bound(currentPosition.begin(), currentPosition.end(), b);
                    if (next == currentPosition.end()) {
                        break;
                    }
                    int c = *next;
                    currentResult = std::max(3, currentResult + 1);
                    a = b;
                    b = c;
                }
                answer = std::max(answer, currentResult);
            }
        }
        return answer;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::string s;
    getline(std::cin, s);
    std::stringstream ss(s);
    std::vector<int> arr;
    int x = 0;
    while (ss >> x) {
        arr.push_back(x);
    }
    Solution solve;
    std::cout << solve.lenLongestFibSubseq(arr);
    return 0;
}

/**



**/
