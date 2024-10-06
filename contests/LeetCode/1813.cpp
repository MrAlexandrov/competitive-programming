#include <bits/stdc++.h>
using namespace std;


template<typename T>
auto StringToVector(const std::string& str) -> std::vector<T> {
    std::stringstream ss{str};

    T x;
    std::vector<T> result;
    while (ss >> x) {
        result.push_back(x);
    }
    return result;
}

bool areSentencesSimilar(string sentence1, string sentence2) {
    std::vector<std::string> words1 = StringToVector<std::string>(sentence1);
    std::vector<std::string> words2 = StringToVector<std::string>(sentence2);

    int n = static_cast<int>(words1.size());
    int m = static_cast<int>(words2.size());

    int l1, r1, l2, r2;

    for (l1 = 0, l2 = 0; l1 < n && l2 < m && words1[l1] == words2[l2]; ++l1, ++l2) {}
    for (r1 = n - 1, r2 = m - 1; r1 >= 0 && r2 >= 0 && words1[r1] == words2[r2]; --r1, --r2) {}

    return (l1 > r1 || l2 > r2);
}

int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    
    std::string sentence1, sentence2;
    std::getline(std::cin, sentence1);
    std::getline(std::cin, sentence2);

    std::cout << areSentencesSimilar(sentence1, sentence2) << '\n';
    return 0;
}

/**

a b a
a b a b a

**/