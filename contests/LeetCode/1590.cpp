#include <bits/stdc++.h>
using namespace std;

auto getVector() {
    std::string s;
    getline(cin, s);
    std::stringstream ss{s};
    std::vector<int> result;
    int x;
    while (ss >> x) {
        result.push_back(x);
    }
    return result;
}

int minSubarray(vector<int>& nums, int p) {
    int n = nums.size();
    int target = 0;
    for (int i = 0; i < n; ++i) {
        nums[i] %= p;
        target += nums[i];
        target %= p;
    }
    if (target == 0) return 0;

    int current_value = 0;
    
    int answer = n;
    unordered_map<int, int> last_remainder;
    last_remainder[0] = -1;

    for (int i = 0; i < n; ++i) {
        current_value += nums[i];
        current_value %= p;

        int needed = (current_value + p - target) % p;
        const auto needed_difference = last_remainder.find(needed);
        
        if (needed_difference != last_remainder.end()) {
            answer = min(answer, i - needed_difference->second);
        }
        last_remainder[current_value] = i;
    }

    return answer == n ? -1 : answer;
}

int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    auto inputVector = getVector();
    auto p = inputVector.back();
    inputVector.pop_back();
    for (auto& i : inputVector) {
        i %= p;
    }
    cout << minSubarray(inputVector, p) << endl;
    return 0;
}

/**

  1 1 1 1 3
0 1 2 0 1 0

**/