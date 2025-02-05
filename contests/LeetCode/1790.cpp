#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    bool areAlmostEqual(std::string s1, std::string s2) {
        int n = static_cast<int>(s1.size());
        std::vector<int> differ;
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) {
                differ.push_back(i);
            }
        }
        int m = static_cast<int>(differ.size());
        if (m == 0) return true;
        if (m != 2) return false;
        int i = differ[0];
        int j = differ[1];
        return (s1[i] == s2[j] && s1[j] == s2[i]);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    
    return 0;
}

/**



**/
