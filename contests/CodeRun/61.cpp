#include <bits/stdc++.h>
using namespace std;

auto getlineVector() {
    string s;
    getline(cin, s);
    stringstream ss{s};

    vector<int> a;
    int x;
    while (ss >> x) {
        a.push_back(x);
    }
    return a;
}

int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    vector<int> a = getlineVector();
    vector<int> b = getlineVector();
    int n = a.size(), m = b.size();

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] == b[j]) {
            cout << a[i] << ' ';
            ++i, ++j;
            continue;
        }
        if (a[i] < b[j]) {
            ++i;
        } else {
            ++j;
        }
    }
    return 0;
}

/**



**/