#include <cassert>
#include <iostream>
#include <string>

class Solution {
public:
    std::string getHappyString(int n, int k) {
        int first = 1;
        for (int i = 1; i < n; ++i, first *= 2) {}
        int second = first << 1;
        int third = first * 3;
        if (third < k) return {};

        --k;
        std::string answer;
        char lastCharacter;
        if (0 <= k && k < first) {
            lastCharacter = 'a';
        } else if (first <= k && k < second) {
            k -= first;
            lastCharacter = 'b';
        } else if (second <= k && k < third) {
            k -= second;
            lastCharacter = 'c';
        }
        answer += lastCharacter;
        auto nextCharacter = [&lastCharacter]() {
            if (lastCharacter == 'a') return std::make_pair('b', 'c');
            if (lastCharacter == 'b') return std::make_pair('a', 'c');
            if (lastCharacter == 'c') return std::make_pair('a', 'b');
            assert(false);
        };
        for (int i = n - 2; i >= 0; --i) {
            auto next = nextCharacter();
            if (((1 << i) & k) == 0) {
                lastCharacter = next.first;
            } else {
                lastCharacter = next.second;
            }
            answer += lastCharacter;
        }
        return answer;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    Solution solve;
    std::cout << solve.getHappyString(n, k);
    return 0;
}

/**

3*2^{n-1}

1   a
2   b
3   c

4   aa
5   ab
6   ac
7   ba
8   bb
9   bc
10  ca
11  cb
12  cc

0   aa
1   ab
2   ac
3   ba
4   bb
5   bc
6   ca
7   cb
8   cc

1   aa
2   ab
3   ac
4   ba
5   bb
6   bc
7   ca
8   cb
9   cc


0   a
1   b
2   c
3   aa
4   ab
5   ac
6   ba
7   bb
8   bc
9   ca
10  cb
11  cc

Решать в четверичной системе, a=1, b=2, c=3

**/
