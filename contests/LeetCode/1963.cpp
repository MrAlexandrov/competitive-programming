#include <bits/stdc++.h>
using namespace std;

int minSwaps(string s) {
    int n = static_cast<int>(s.size());

    int counter = 0;
    int minValue = 0;
    for (const auto& i : s) {
        if (i == '[') {
            ++counter;
        } else {
            --counter;
            minValue = std::min(minValue, counter);
        }
    }

    return ((-minValue) + 1) / 2;
}

int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    
    std::string s;
    std::cin >> s;
    std::cout << minSwaps(s) << endl; 

    return 0;
}

/**

[[[]]]][[]

**/