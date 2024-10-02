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

int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    vector<int> arr = getVector();
    int n = arr.size();

    set<int> st;
    for (const auto& i : arr) {
        st.insert(i);
    }
    unordered_map<int, int> number_to_rank;
    int current_rank = 1;
    for (const auto& i : st) {
        number_to_rank[i] = current_rank++;
    }

    for (const auto& i : arr) {
        cout << number_to_rank[i] << ' ';
    }
    return 0;
}

/**



**/