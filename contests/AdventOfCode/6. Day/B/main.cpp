#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll time, ll distance) {
    auto check = [&] (ll current_time) -> ll {
        return (time - current_time) * current_time;
    };
    ll mid = (time + 1) >> 1;
    ll left, right;
    ll l = 0, r = mid;
    while (r - l > 1) {
        ll m = l + r >> 1;
        if (check(m) <= distance) {
            l = m;
        } else {
            r = m;
        }
    }
    left = r;
    l = (time & 1 ? mid + 1 : mid), r = time;
    while (r - l > 1) {
        ll m = l + r >> 1;
        if (check(m) > distance) {
            l = m;
        } else {
            r = m;
        }
    }
    right = r;
    return right - left;
}

ll str_to_ll(string x) {
    ll res = 0;
    for (char &i : x) {
        res *= 10;
        res += i - '0';
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    string temp;
    cin >> temp;
    int n = 4;
    string times;
    for (int i = 0; i < n; ++i) {
        string now;
        cin >> now;
        times += now;
    }
    ll time = str_to_ll(times);
    cin >> temp;
    string distances;
    for (int i = 0; i < n; ++i) {
        string now;
        cin >> now;
        distances += now;
    }
    ll distance = str_to_ll(distances);
    cout << solve(time, distance);
    return 0;
}

/**
(time - i) * i
7487785

**/
