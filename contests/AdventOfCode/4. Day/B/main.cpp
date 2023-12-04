#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 193;

vector <int> cnt(N, 1);
int ptr = 0;

void solve() {
    string temp;
    cin >> temp >> temp;
    vector <int> a(10);
    for (int &i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    cin >> temp;
    vector <int> b(25);
    for (int &i : b) {
        cin >> i;
    }
    sort(b.begin(), b.end());
    vector <int> c;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c));
    int k = c.size();
    for (int i = ptr + 1; i < ptr + 1 + k && i < N; ++i) {
        cnt[i] += cnt[ptr];
    }
    ++ptr;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int t = N;
    ///cin >> t;
    while (t--) {
        solve();
    }
    cout << accumulate(cnt.begin(), cnt.end(), 0);
    return 0;
}

/**


**/
