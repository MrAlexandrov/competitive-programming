#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.txt", "r", stdin);
    ///freopen("input.txt", "w", stdout);
    ll x;
    cin >> x;
    vector <ll> a, b;
    for (ll i = 0; i <= (ll)1e7; ++i) {
        a.push_back(i * i);
    }
    for (ll i = 0; i <= (ll)1e5; ++i) {
        b.push_back(i * i * i);
    }
    int cnt = 0;
    int it1 = 0, it2 = 0;
    int n = a.size(), m = b.size();
    while (it1 < n && it2 < m && cnt < x) {
        if (a[it1] == b[it2]) {
            //cout << a[it1] << ' ';
            ++it1;
            ++it2;
        } else {
            if (a[it1] < b[it2]) {
                //cout << a[it1] << ' ';
                ++it1;
            } else {
                //cout << b[it2] << ' ';
                ++it2;
            }
        }
        ++cnt;
    }
    while (it1 < n && cnt < x) {
        //cout << a[it1] << ' ';
        ++it1;
        ++cnt;
    }
    while (it2 < m && cnt < x) {
        //cout << b[it2] << ' ';
        ++it2;
        ++cnt;
    }
    //cout << endl;
    if (it1 < n && it2 < m) {
        cout << min(a[it1], b[it2]);
    } else {
        if (it1 < n) {
            cout << a[it1];
        } else {
            cout << b[it2];
        }
    }
    return 0;
}

/**
5e6 * 5e6 * 5e6 = 125e18

985689808438134743
7942526186944865599
9105735405517618392

3037000499.98
2097152

10 = 125
100 = 132651
1000 = 127263527
10000 = 125600960512
100000 = 125127543354913
1000000 = 125029252281559319
10000000 = 9221340288571163992


10000000
99080961339364
**/

