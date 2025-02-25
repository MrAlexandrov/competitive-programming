#include <iostream>
#include <vector>

class Solution {
private:
    constexpr static int MOD = 1'000'000'007;
public:
    int numOfSubarrays(std::vector<int>& arr) {
        std::vector<int> cnt = {1, 0};
        int answer = 0;
        int sum = 0;
        for (const auto& x : arr) {
            sum += x;
            answer = (answer + cnt[(sum & 1) ^ 1]) % MOD;
            ++cnt[sum & 1];
        }
        return answer;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (auto& i : arr) {
        std::cin >> i;
    }
    Solution solve;
    std::cout << solve.numOfSubarrays(arr);
    return 0;
}

/**

n + (n - 2) + (n - 4) + (n - 6) + ...

**/
