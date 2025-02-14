#include <iostream>
#include <vector>

class ProductOfNumbers {
public:
    ProductOfNumbers() {
        Product_.reserve(101);
    }
    
    void add(int num) {
        if (static_cast<int>(num)) {
            Product_.push_back(Product_.back() * num);
        } else {
            Product_ = {1};
        }
    }
    
    int getProduct(int k) {
        int m = static_cast<int>(Product_.size());
        return (k < m ? Product_.back() / Product_[m - k - 1] : 0);
    }
private:
    std::vector<int> Product_ = {1};
};

/**
* Your ProductOfNumbers object will be instantiated and called as such:
* ProductOfNumbers* obj = new ProductOfNumbers();
* obj->add(num);
* int param_2 = obj->getProduct(k);
*/

int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    ProductOfNumbers solve;
    for (int i = 0; i < n; ++i) {
        std::string command;
        std::cin >> command;
        if (command == "ProductOfNumbers") continue;
        if (command == "add") {
            int num;
            std::cin >> num;
            solve.add(num);
        }
        if (command == "getProduct") {
            int k;
            std::cin >> k;
            std::cout << solve.getProduct(k) << "\n";
        }
    }
    return 0;
}

/**



**/
