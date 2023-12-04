#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> pii;

const int INF = INT_MAX;

bool cmp(pii a, pii b) {
    if (a.first == b.first) {
        return true;
    } else {
        return a.first < b.first;
    }
}

struct item {
    int value;
    int cnt;
    vector <int> pos;
    item() {
        val = 0;
        cnt = 0;
    }
    item(int x, int ind) {
        val = x;
        cnt = 1;
        pos.push_back(ind);
    }
    bool operator<(const item& other) const {
        return value < other.value;
    }
};

template <typename T>
class MySet : public std::map<T> {
public:
    std::pair<typename std::set<T>::iterator, bool> insert(const T& x) {
        if (valueIsValidForInsertion(value)) {
            return std::set<T>::insert(value);
        } else {
            // Обработка невалидного значения
            return std::make_pair(std::set<T>::end(), false);
        }
    }
};


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector <pii> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    int mn = INF, mx = -INF;
    for (int i = 0; i < m; ++i) {
        mn = min(mn, a[i].second);
        mx = max(mx, a[i].second);
    }
    cout << mx - mn + 1;
    return 0;
}

/**


**/
