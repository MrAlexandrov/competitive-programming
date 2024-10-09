#include <iostream>
#include <string>

int minAddToMakeValid(std::string s) {
    // int n = static_cast<int>(s.size());
    int minValue = 0, maxValue = 0;
    int currentValue = 0;
    for (const auto& i : s) {
        if (i == ')') {
            ++currentValue;
            minValue = std::max(minValue, currentValue);
        } else {
            --currentValue;
        }
    }
    currentValue = 0;
    for (auto i = s.rbegin(), end = s.rend(); i != end; ++i) {
        if (*i == '(') {
            ++currentValue;
            maxValue = std::max(maxValue, currentValue);
        } else {
            --currentValue;
        }
    }
    return minValue + maxValue;
}

int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);

    std::string s;
    std::cin >> s;
    std::cout << minAddToMakeValid(s) << std::endl;

    return 0;
}

/**



**/