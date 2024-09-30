#include <bits/stdc++.h>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    string s;
    getline(cin, s);

    stringstream ss{s};

    vector<int> a;
    int x;
    while (ss >> x) {
        a.push_back(x);
    }
    int n = a.size();

    int answer = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
            ++answer;
        }
    }
    cout << answer << endl;
    return 0;
}

/**



**/