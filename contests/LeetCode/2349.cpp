#include <cassert>
#include <iostream>
#include <memory>
#include <set>
#include <unordered_map>

class NumberContainers {
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        auto previousNumber = position.find(index);
        if (previousNumber != position.end()) {
            auto previousSet = minimum.find(previousNumber->second);
            assert(previousSet != minimum.end());
            previousSet->second.erase(index);
        }
        position[index] = number;
        minimum[number].insert(index);
    }
    
    int find(int number) {
        auto minimumPosition = minimum.find(number);
        if (minimumPosition == minimum.end()) return -1;
        return minimumPosition->second.empty() ? -1 : *(minimumPosition->second.cbegin());
    }
private:
    // number -> {indexes}
    std::unordered_map<int, std::set<int>> minimum;
    // index -> number
    std::unordered_map<int, int> position;
};
    
    /**
     * Your NumberContainers object will be instantiated and called as such:
     * NumberContainers* obj = new NumberContainers();
     * obj->change(index,number);
     * int param_2 = obj->find(number);
     */

int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    std::unique_ptr<NumberContainers> obj = std::make_unique<NumberContainers>();
    // NumberContainers* obj = new NumberContainers();
    for (int i = 0; i < n; ++i) {
        std::string command;
        std::cin >> command;
        if (command == "NumberContainers") {
            ///
        } else if (command == "find") {
            int number;
            std::cin >> number;
            std::cout << obj->find(number) << std::endl;
        } else if (command == "change") {
            int index, number;
            std::cin >> index >> number;
            obj->change(index, number);
        }
    }

    return 0;
}

/**



**/
