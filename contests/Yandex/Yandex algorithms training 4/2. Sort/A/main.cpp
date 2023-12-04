#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int hoarePartition(vector<int> &a, int l, int r, int x) {
    int lower = l, mid = l, higher = l;
    for (int i = l; i < r; ++i) {
        if (a[i] == x) {
            swap(a[i], a[mid]);
            ++mid;
            ++higher;
        } else {
            if (a[i] < x) {
                swap(a[i], a[mid]);
                swap(a[mid], a[lower]);
                ++lower;
                ++mid;
                ++higher;
            } else {
                ++higher;
            }
        }
    }
    return lower;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int x;
    cin >> x;
    int pos = hoarePartition(a, 0, n, x);
    /*for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;*/
    cout << pos << ' ' << n - pos;
    /*for (const int &i : a) {
        cout << i << ' ';
    }
    cout << endl;*/
    return 0;
}

/**
        l     x   h
l l l l x x x h h .

**/
