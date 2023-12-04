#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int &i : a) {
        cin >> i;
    }
    deque <int> mn;
    for (int i = 0; i < k - 1; ++i) {
        while (!mn.empty() && a[i] < a[mn.back()]) {
            mn.pop_back();
        }
        mn.push_back(i);
    }
    for (int i = k - 1; i < n; ++i) {
        while (!mn.empty() && a[i] < a[mn.back()]) {
            mn.pop_back();
        }
        mn.push_back(i);
        while (!mn.empty() && mn.front() < i - k + 1) {
            mn.pop_front();
        }
        cout << a[mn.front()] << ' ';
    }
    return 0;
}

/**
11 3
8 764 1 3 85 2 4 5 77 1 5

**/
