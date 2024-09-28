#include <bits/stdc++.h>
using namespace std;

class MyCircularDeque {
public:
    MyCircularDeque(int k) : max_size(k) {}
    
    bool insertFront(int value) {
        if (data_.size() == max_size) return false;
        data_.push_front(value);
        return true;
    }
    
    bool insertLast(int value) {
        if (data_.size() == max_size) return false;
        data_.push_back(value);
        return true;
    }
    
    bool deleteFront() {
        if (data_.empty()) return false;
        data_.pop_front();
        return true;
    }
    
    bool deleteLast() {
        if (data_.empty()) return false;
        data_.pop_back();
        return true;
    }
    
    int getFront() {
        if (data_.empty()) return -1;
        return data_.front();
    }
    
    int getRear() {
        if (data_.empty()) return -1;
        return data_.back();
    }
    
    bool isEmpty() {
        return data_.empty();
    }
    
    bool isFull() {
        return data_.size() == max_size;
    }

private:
    int max_size;
    deque<int> data_;
};

int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    
    return 0;
}

/**



**/