#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int lomutoPartition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];  // Опорный элемент (можно выбрать любой другой)
    int i = low;

    for (int j = low + 1; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[low], arr[i]);
    return i;
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
    lomutoPartition(a, 0, n);
    for (const int &i : a) {
        cout << i << ' ';
    }
    return 0;
}

/**


**/
