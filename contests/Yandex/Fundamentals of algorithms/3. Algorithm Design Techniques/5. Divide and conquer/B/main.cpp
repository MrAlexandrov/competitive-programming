#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = INT_MAX;
int n;
vector <vector <int>> a;

void nxt(vector <int> &x, int &it, vector <int> &ptrs) {
    int mn = INF;
    int it_mn = -1;
    for (int i = 0; i < n; ++i) {
        vector <int> &now = a[i];
        int &j = ptrs[i];
        if (!(j < now.size())) continue;
        if (now[j] < mn) {
            mn = now[j];
            it_mn = i;
        }
    }
    x[it++] = mn;
    ++ptrs[it_mn];
}

void merge(vector <int> &x, const int &k) {
    int it = 0;
    vector <int> ptrs(n, 0);
    while (it < k) {
        nxt(x, it, ptrs);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    cin >> n;
    a.resize(n);
    int k;
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        k += m;
        a[i].resize(m);
        for (int &j : a[i]) {
            cin >> j;
        }
    }
    vector <int> ans(k);
    merge(ans, k);
    for (const int &i : ans) {
        cout << i << ' ';
    }
    return 0;
}

/**
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    multiset <int> ans;
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            ans.insert(x);
        }
    }
    for (const int &i : ans) {
        cout << i << ' ';
    }
    return 0;
}


**/
