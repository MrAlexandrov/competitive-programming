#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int lomutoPartition(vector<int> &arr, int low, int high) {
    int pivot = arr[(low + high) / 2];  // Опорный элемент (можно выбрать любой другой)
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

void quickSort(vector <int> &arr, int low, int high) {
    if (low < high) {
        int pivotIndex = lomutoPartition(arr, low, high);
        quickSort(arr, low, pivotIndex);
        quickSort(arr, pivotIndex + 1, high);
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
