#include <bits/stdc++.h>
#include <csetjmp>
using namespace std;

int minLength(string s) {
    int n = static_cast<int>(s.size());

    std::transform(s.begin(), s.end(), s.begin(),
        [](char& ch) { return ch -= 'A'; }
    );

    std::vector<int> matchingPair = {
        1,
        -1,
        3,
        -1
    };

    std::vector<int> stack;
    stack.reserve(n);

    auto match = [&matchingPair](const int& a, const int& b) {
        if (a >= 4) return false;
        return matchingPair[a] == b;
    };

    for (const auto& ch : s) {
        if (stack.empty() || !match(stack.back(), ch)) {
            stack.push_back(ch);
        } else {
            stack.pop_back();
        }
    }

    return static_cast<int>(stack.size());
}

int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    
    std::string s;
    cin >> s;
    std::cout << minLength(s) << '\n';

    return 0;
}

/**



**/