#include <bits/stdc++.h>
using namespace std;

struct Event {
    int start;
    int end;
};

bool intersect(const Event& lhs, const Event& rhs) {
    return !(lhs.end <= rhs.start
          || rhs.end <= lhs.start);
}

const auto compare_start = [](const Event& x, const Event& y) -> bool {
    return x.start < y.start;
};

const auto compare_reverse_end = [](const Event& x, const Event& y) -> bool {
    return x.end > y.end;
};

class MyCalendar {
public:
    MyCalendar() : start_order(compare_start), end_reverse_order(compare_reverse_end) {}
    
    bool book(int start, int end) {
        const Event current{start, end};

        auto find_next_start = start_order.lower_bound(current); //lower_bound(start_order.begin(), start_order.end(), current);
        auto find_prev_end =  end_reverse_order.lower_bound(current); //lower_bound(end_reverse_order.begin(), end_reverse_order.end(), current);

        if (find_next_start != start_order.end()) {
            if (intersect(current, *find_next_start)) {
                return false;
            }
        }
        if (find_next_start != start_order.begin() && !start_order.empty()) {
            --find_next_start;
            if (intersect(current, *find_next_start)) {
                return false;
            }
        }

        if (find_prev_end != end_reverse_order.end()) {
            if (intersect(current, *find_prev_end)) {
                return false;
            }
        }
        if (find_prev_end != end_reverse_order.begin() && !end_reverse_order.empty()) {
            --find_prev_end;
            if (intersect(current, *find_prev_end)) {
                return false;
            }
        }

        start_order.insert(current);
        end_reverse_order.insert(current);

        return true;
    }

private:
    set<Event, decltype(compare_start)> start_order;
    set<Event, decltype(compare_reverse_end)> end_reverse_order;   
};


int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    unique_ptr<MyCalendar> calendar = make_unique<MyCalendar>();

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int start, end;
        cin >> start >> end;
        cout << calendar->book(start, end) << '\n';
    }
    cout << endl;
    return 0;
}

/**



**/