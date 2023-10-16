#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void prime_div(int x, vector <pair <int, int>> &d) {
    if (x % 2 == 0) {
        d.push_back({2, 0});
        while (x % 2 == 0) {
            d.back().second++;
            x /= 2;
        }
    }
    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) {
            d.push_back({i, 0});
            while (x % i == 0) {
                d.back().second++;
                x /= i;
            }
        }
    }
    if (x > 1) {
        d.push_back({x, 1});
    }
}

ll solve() {
    ll res = 1;
    int q, r;
    cin >> q >> r;
    //int check = q * (r - 1);
    vector <pair <int, int>> d1, d2;
    vector <pair <int, int>> sum;
    prime_div(q, d1);
    prime_div(r - 1, d2);
    if (d1.empty() || d2.empty()) {
        if (d1.empty() && d2.empty()) {
            return 1;
        }
        if (d1.empty()) {
            sum = d2;
        }
        if (d2.empty()) {
            sum = d1;
        }
    } else {
        int i = 0, j = 0;
        int n = d1.size(), m = d2.size();
        while (i < n || j < m) {
            if (i == n) {
                sum.push_back(d2[j]);
                ++j;
                continue;
            }
            if (j == m) {
                sum.push_back(d1[i]);
                ++i;
                continue;
            }
            if (d1[i].first == d2[j].first) {
                sum.push_back({d1[i].first, d1[i].second + d2[j].second});
                ++i;
                ++j;
                continue;
            }
            if (d1[i].first < d2[j].first) {
                sum.push_back(d1[i]);
                ++i;
                continue;
            }
            if (d1[i].first > d2[j].first) {
                sum.push_back(d2[j]);
                ++j;
                continue;
            }
        }
    }
    for (auto [num, cnt] : sum) {
        res *= (cnt + 1);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    /*
    int x;
    cin >> x;
    vector <pair <int, int>> a;
    prime_div(x, a);
    for (auto i : a) {
        cout << i.first << ' ' << i.second << endl;
    }
    return 0;*/
    int t = 1;
    //cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}

/**


**/
