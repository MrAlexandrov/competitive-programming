#include <iostream>
#include <string>

class Solution {
public:
    std::string removeOccurrences(std::string s, std::string part) {
        const int m = static_cast<int>(part.size());

        auto position = s.find(part);
        if (position != std::string::npos) {
            std::string newString = s;
            newString.erase(position, m);
            return removeOccurrences(newString, part);
        }
        return s;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    std::string s, part;
    std::cin >> s >> part;
    Solution solve;
    std::cout << solve.removeOccurrences(s, part);
    return 0;
}

/**



**/
