#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

mt19937 rnd(time(0));

int my_rnd(int l, int r) {
    return rnd() % (r - l) + l;
}

pair <int, int> hoarePartition(vector<int> &a, int l, int r) {
    int x = a[rnd() % (r - l) + l];
    int lower = l, mid = l;
    for (int i = l; i < r; ++i) {
        if (a[i] == x) {
            swap(a[i], a[mid]);
            ++mid;
        } else {
            if (a[i] < x) {
                swap(a[i], a[mid]);
                swap(a[mid], a[lower]);
                ++lower;
                ++mid;
            }
        }
    }
    return {lower, mid};
}

void quickSort(vector <int> &arr, int l, int r) {
    if (l < r) {
        auto [lower, mid] = hoarePartition(arr, l, r);
        quickSort(arr, l, lower);
        quickSort(arr, mid, r);
    }
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
    quickSort(a, 0, n);
    for (const int &i : a) {
        cout << i << ' ';
    }
    return 0;
}

/**


**/
