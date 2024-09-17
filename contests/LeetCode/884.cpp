#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <array>
#include <sstream>

struct Storage {
    using const_iterator = std::unordered_map<std::string, uint32_t>::const_iterator;

    std::string sentence;
    std::unordered_map<std::string, uint32_t> amount;
    Storage() = default;
    Storage(const std::string& other) : sentence(other) { Parse(); }
    Storage(std::string&& other) : sentence(move(other)) { Parse(); }

    void initialize(const std::string& other) {
        sentence = other;
        Parse();
    }

    void Parse() {
        std::stringstream temp{sentence};
        std::string word;
        while (temp >> word) {
            ++amount[word];
        }
    }

    bool contains(const std::string& value) const noexcept {
        return amount.contains(value);
    }

    const_iterator begin() const noexcept {
        return amount.begin();
    }
    
    const_iterator end() const noexcept {
        return amount.end();
    }
};

auto findUncommon(const Storage& x, const Storage& y) -> std::vector <std::string> {
    std::vector <std::string> result;
    for (const auto& [word, amount] : x) {
        if (amount == 1 && !y.contains(word)) {
            result.push_back(word);
        }
    }
    for (const auto& [word, amount] : y) {
        if (amount == 1 && !x.contains(word)) {
            result.push_back(word);
        }
    }
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    std::array <Storage, 2> Storages;
    for (int i = 0, end = static_cast<int>(Storages.size()); i < end; ++i) {
        std::string temp;
        std::getline(std::cin, temp);
        Storages[i].initialize(temp);
    }
    for (const auto& word : findUncommon(Storages[0], Storages[1])) {
        std::cout << word << ' ';
    }
    return 0;
}

/**

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstream ss1(s1), ss2(s2);
        unordered_map<string, uint32_t> amount;
        string word;
        while (ss1 >> word) {
            ++amount[word];
        }
        while (ss2 >> word) {
            ++amount[word];
        }
        vector <string> result;
        for (const auto& [word, number] : amount) {
            if (number == 1) {
                result.push_back(word);
            }
        }
        return result;
    }
};

**/