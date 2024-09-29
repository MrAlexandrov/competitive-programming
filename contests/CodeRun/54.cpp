#include <bits/stdc++.h>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    
    int n;
    cin >> n;
    unordered_map <string, int> languages;
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            string current_language;
            cin >> current_language;
            ++languages[current_language];
        }
    }

    vector<string> all_knows;
    vector<string> exact_one_knows;
    for (const auto& [language, amount] : languages) {
        if (amount == n) {
            all_knows.push_back(language);
        }
        exact_one_knows.push_back(language);
    }
    
    cout << all_knows.size() << '\n';
    for (const auto& i : all_knows) {
        cout << i << '\n';
    }
    
    cout << exact_one_knows.size() << '\n';
    for (const auto& i : exact_one_knows) {
        cout << i << '\n';
    }
    
    cout << endl;
    return 0;
}

/**



**/