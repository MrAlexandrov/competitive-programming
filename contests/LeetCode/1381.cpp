#include <bits/stdc++.h>
using namespace std;

class CustomStack {
public:
    CustomStack(int maxSize) : max_size(maxSize) {
        
    }
    
    void push(int x) {
        if (data_.size() != max_size) {
            data_.emplace_back(x, 0);
        }
    }
    
    int pop() {
        if (data_.empty()) return -1;
        int current_size = data_.size(); 

        int result = data_[current_size - 1].first + data_[current_size - 1].second;
        if (current_size > 1) {
            data_[current_size - 2].second += data_[current_size - 1].second;
        }
        data_.pop_back();
        return result;
    }
    
    void increment(int k, int val) {
        --k;
        if (k >= data_.size()) {
            if (data_.empty()) return;
            data_.back().second += val;
        } else {
            data_[k].second += val;
        }
    }

private:
    int max_size;
    vector<pair<int, int>> data_; // value, add
};


int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    
    return 0;
}

/**



**/