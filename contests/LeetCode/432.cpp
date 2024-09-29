#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>

class AllOne {
public:
    AllOne() {
        
    }
    
    void inc(std::string key) {
        int& current_amount = str_to_amount[key];
        amount_to_str[current_amount].erase(key);
        if (amount_to_str[current_amount].empty()) {
            amount_to_str.erase(current_amount);
        }

        ++current_amount;
        amount_to_str[current_amount].insert(key);
    }
    
    void dec(std::string key) {
        int& current_amount = str_to_amount[key];
        amount_to_str[current_amount].erase(key);
        if (amount_to_str[current_amount].empty()) {
            amount_to_str.erase(current_amount);
        }

        --current_amount;
        if (current_amount != 0) {
            amount_to_str[current_amount].insert(key);
        } else {
            str_to_amount.erase(key);
        }
    }
    
    std::string getMaxKey() {
        if (amount_to_str.empty()) return {};
        return *(amount_to_str.rbegin()->second.begin());
    }
    
    std::string getMinKey() {
        if (amount_to_str.empty()) return {};
        return *(amount_to_str.begin()->second.begin());
    }

private:
    std::unordered_map<std::string, int> str_to_amount;
    std::map<int, std::unordered_set<std::string>> amount_to_str;
};


int main() {
    
    return 0;
}

/**



**/