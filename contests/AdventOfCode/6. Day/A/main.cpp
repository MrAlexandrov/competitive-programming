#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int time, int distance) {
    auto check = [&] (int current_time) {
        return (time - current_time) * current_time;
    };
    int mid = (time + 1) >> 1;
    int left, right;
    int l = 0, r = mid;
    while (r - l > 1) {
        int m = l + r >> 1;
        if (check(m) < distance) {
            l = m;
        } else {
            r = m;
        }
    }
    left = r;
    l = (time & 1 ? mid + 1 : mid), r = time;
    while (r - l > 1) {
        int m = l + r >> 1;
        if (check(m) >= distance) {
            l = m;
        } else {
            r = m;
        }
    }
    right = r;
    return right - left;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    string temp;
    cin >> temp;
    int n = 4;
    vector <int> times(n);
    for (int &i : times) {
        cin >> i;
    }
    cin >> temp;
    vector <int> distances(n);
    for (int &i : distances) {
        cin >> i;
    }
    int res = 1;
    for (int i = 0; i < n; ++i) {
        res *= solve(times[i], distances[i]);
    }
    cout << res;
    return 0;
}

/**
(time - i) * i


**/
