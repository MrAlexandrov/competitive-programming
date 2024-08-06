#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        vector <long long> a(n);
        long long max_element = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            max_element = max(max_element, a[i]);
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] < max_element) {
                int temp = (max_element - a[i]) / (2 * k);
                a[i] += (2 * k) * temp;
            }
        }
        sort(a.begin(), a.end());
        for (int i : a) {
            cout << i << ' ';
        }
        cout << '\n';
        int answer = a.back();
        for (int i = 0; i < n; ++i) {
            if (a[i] + k < a.back()) {
                a[i] += 2 * k;
            }
        }
        for (int i : a) {
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}