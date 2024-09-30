#include <bits/stdc++.h>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
        --i;
    }
    vector<int> amount(k, 0);
    int different = 0;
    int l = 0, r = 0;
    int current_min_length = n;
    int answer_l = 0, answer_r = n;
    auto tryUpdateAnswer = [&]() {
        if (different != k || r > n) return;
        int new_length = r - l;
        if (new_length < current_min_length) {
            current_min_length = new_length;
            answer_l = l;
            answer_r = r;
        }
    };
    while (r < n) {
        while (r < n && different < k) {
            int current_element = a[r];
            if (amount[current_element]++ == 0) {
                ++different;
            }
            ++r;
        }
        tryUpdateAnswer();
        while (different >= k) {
            int current_element = a[l];
            if (--amount[current_element] == 0) {
                --different;
            }
            ++l;
            tryUpdateAnswer();
        }
    }
    cout << answer_l + 1 << ' ' << answer_r;
    return 0;
}

/**



**/