#include <iterator>
#include <limits>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <limits>

auto getVector() {
    std::string s;
    getline(std::cin, s);
    std::stringstream ss{s};
    std::vector<int> result;
    int x;
    while (ss >> x) {
        result.push_back(x);
    }
    return result;
}

constexpr int INF = std::numeric_limits<int>::max();

struct Item {
    int minimum = INF;

    Item() {}
    explicit Item(int value) : minimum(value) {}
};

Item Combine(const Item& lhs, const Item& rhs) {
    Item result;
    result.minimum = std::min(lhs.minimum, rhs.minimum);
    return result;
}

class SegmentTree {
public:

    explicit SegmentTree(int n) : n_(n), data_() {
        data_.resize(n_ << 2);
    }

    int GetMinimum(int l, int r) const {
        return GetMinimum(0, 0, n_, l, r);
    }

    void Update(int i, int value) {
        Update(0, 0, n_, i, value);
    }

private:
    int n_;
    std::vector<Item> data_;

    int GetMinimum(int v, int tl, int tr, int l, int r) const {
        if (r <= tl || tr <= l) {
            return std::numeric_limits<int>::max();
        }

        if (l <= tl && tr <= r) {
            return data_[v].minimum;
        }
        
        int tm = (tl + tr) >> 1;
        return std::min(
                     GetMinimum(2 * v + 1, tl, tm, l, r), 
                     GetMinimum(2 * v + 2, tm, tr, l, r)
        );
    }

    void Update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr - 1) { 
            data_[v].minimum = std::min(data_[v].minimum, val);
            return;
        }

        int tm = (tl + tr) >> 1;
        if (pos < tm) {
            Update(2 * v + 1, tl, tm, pos, val);
        } else {
            Update(2 * v + 2, tm, tr, pos, val);
        }
        
        data_[v] = Combine(data_[2 * v + 1], data_[2 * v + 2]);
    }
};

int maxWidthRamp(std::vector<int>& nums) {
    int maxValue = *max_element(nums.cbegin(), nums.cend());
    SegmentTree segment_tree(maxValue + 1);

    int answer = 0;

    for (auto i = nums.begin(), end = nums.end(); i != end; ++i) {
        int current_value = *i;
        int current_position = static_cast<int>(std::distance(nums.begin(), i));

        int l = 0, r = current_value + 1; // min[l, r)
        int minimum = segment_tree.GetMinimum(l, r);

        if (minimum == INF) {
            segment_tree.Update(current_value, current_position);
            continue;
        }

        answer = std::max(answer, current_position - minimum);

        segment_tree.Update(current_value, current_position);
    }

    return answer;
}

int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    
    std::vector<int> nums = getVector();
    std::cout << maxWidthRamp(nums) << std::endl;

    return 0;
}

/**



**/