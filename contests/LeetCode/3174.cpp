#include <cctype>
#include <iostream>
#include <string>
#include <utility>

class Solution {
public:
    int FindNumber(const std::string& s) {
        int n = static_cast<int>(s.size());
        for (int i = 0; i < n; ++i) {
            if (std::isdigit(s[i])) {
                return i;
            }
        }
        return -1;
    }

    int FindNearestCharacter(int index, const std::string& s) {
        int n = static_cast<int>(s.size());
        for (int i = 1; i < n; ++i) {
            int left = index - i;
            int right = index + i;
            if (0 <= left && left < n) {
                if (!std::isdigit(s[left])) {
                    return left;
                }
            }
            if (0 <= right && right < n) {
                if (!std::isdigit(s[right])) {
                    return right;
                }
            }
        }
        return -1;
    }

    std::string clearDigits(std::string s) {
        int n = static_cast<int>(s.size());
        for (;;) {
            int index = FindNumber(s);
            if (index == -1) break;

            int toRemove = FindNearestCharacter(index, s);
            if (toRemove == -1) break;

            if (index > toRemove) {
                std::swap(index, toRemove);
            }
            s.erase(toRemove, 1);
            s.erase(index, 1);
        }
        return s;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    std::string s;
    std::cin >> s;
    Solution solve;
    std::cout << solve.clearDigits(s);
    return 0;
}

/**



**/
