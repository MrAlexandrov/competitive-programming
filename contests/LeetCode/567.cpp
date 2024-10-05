#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    if (n > m) return false;
    unordered_map<char, int> m1, m2;
    for (const auto& c : s1) {
        ++m1[c];
    }
    int l = 0, r;
    for (r = 0; r < n; ++r) {
        ++m2[s2[r]];
    }
    if (m1 == m2) return true;

    while (r < m) {
        --m2[s2[l]];
        if (m2[s2[l]] == 0) {
            m2.erase(s2[l]);
        }
        ++m2[s2[r]];

        ++l, ++r;
        if (m1 == m2) return true;
    }

    return m1 == m2;
}

int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    string s1, s2;
    cin >> s1 >> s2;
    cout << checkInclusion(s1, s2) << endl;
    return 0;
}

/**



**/