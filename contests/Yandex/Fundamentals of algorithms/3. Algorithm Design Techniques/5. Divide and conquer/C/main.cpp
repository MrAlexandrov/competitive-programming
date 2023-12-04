#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void my_merge(vector <int> &a, const int &l, const int &m, const int &r) {
    vector <int> res(r - l);
    int i = 0, j = 0;
    while (l + i < m && m + j < r) {
        if (a[l + i] < a[m + j]) {
            res[i + j] = a[l + i];
            ++i;
        } else {
            res[i + j] = a[m + j];
            ++j;
        }
    }

    while (l + i < m) {
        res[i + j] = a[l + i];
        ++i;
    }
    while (m + j < r) {
        res[i + j] = a[m + j];
        ++j;
    }
    for (int t = 0; t < i + j; ++t) {
        a[l + t] = res[t];
    }
}

void merge_sort(vector <int> &a, const int &l, const int &r) {
    if (r - l == 1) return;
    if (r - l == 2) {
        if (a[l] > a[l + 1]) {
            swap(a[l], a[l + 1]);
        }
        return;
    }
    int m = (l + r) / 2;
    merge_sort(a, l, m);
    merge_sort(a, m, r);
    my_merge(a, l, m, r);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int &i : a) {
        cin >> i;
    }
    int l = 0, r = n;
    merge_sort(a, l, r);
    for (const int &i : a) {
        cout << i << ' ';
    }
    return 0;
}

/**


**/
