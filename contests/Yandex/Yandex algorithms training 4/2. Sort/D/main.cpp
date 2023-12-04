#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void my_merge(vector <int> &a, int l, int m, int r) {
    vector <int> res(r - l);
    int i = l, j = m;
    while (i < m && j < r) {
        int pos = (i - l) + (j - m);
        if (a[i] < a[j]) {
            res[pos] = a[i];
            ++i;
        } else {
            res[pos] = a[j];
            ++j;
        }
    }
    while (i < m) {
        int pos = (i - l) + (j - m);
        res[pos] = a[i];
        ++i;
    }
    while (j < r) {
        int pos = (i - l) + (j - m);
        res[pos] = a[j];
        ++j;
    }
    for (int ind = l; ind < r; ++ind) {
        a[ind] = res[ind - l];
    }
    res.clear();
}

void merge_sort(vector <int> &a, int l, int r) {
    if (r - l < 2) {
        return;
    }
    int m = (l + r) / 2;
    merge_sort(a, l, m);
    merge_sort(a, m, r);
    my_merge(a, l, m, r);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int &i : a) {
        cin >> i;
    }
    merge_sort(a, 0, n);
    for (int &i : a) {
        cout << i << ' ';
    }
    return 0;
}

/**


**/
