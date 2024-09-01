#include <bits/stdc++.h>
#include <vector>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (auto& i : p) {
            cin >> i;
            --i;
        }
        string s;
        cin >> s;

        vector<bool> visited(n, false);

        vector<int> answer(n, 0);

        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;

            vector<int> current;
            current.push_back(i);

            int count_black = (s[i] == '0');
            visited[i] = true;
            int now = p[i];
            while (now != i) {
                count_black += (s[now] == '0');
                visited[now] = true;
                current.push_back(now);
                now = p[now];
            }

            for (auto& j : current) {
                answer[j] = count_black;
            }
        }

        for (auto& i : answer) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}

/**



**/