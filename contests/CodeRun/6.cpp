#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define DEBUG 1
#else 
    #define DEBUG 0
#endif // LOCAL

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int& i : a) {
        cin >> i;
    }
    int m;
    cin >> m;
    vector <int> b(m);
    for (int& j : b) {
        cin >> j;
    }
    
    // самая длинная подпоследовательность, если мы просмотрели i элементов первой и j второй
    vector <vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // откуда мы пришли, чтобы получить ответ
    vector <vector<pair<int, int>>> prev(n + 1, vector<pair<int, int>>(m + 1, {0, 0})); 

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1; 
                prev[i][j] = {i - 1, j - 1};
            } else {
                auto get_max = [&](int i, int j) {
                    int maximum = max({
                        dp[i - 1][j - 1],
                        dp[i - 1][j],
                        dp[i][j - 1]
                    });
                    pair <int, int> previous;
                    if (dp[i - 1][j - 1] == maximum) {
                        previous = {i - 1, j - 1};
                    } else if (dp[i - 1][j] == maximum) {
                        previous = {i - 1, j};
                    } else if (dp[i][j - 1] == maximum) {
                        previous = {i, j - 1};
                    } else {
                        assert(false);
                    }

                    return make_pair(maximum, previous);
                };

                auto [new_max, new_prev] = get_max(i, j);

                dp[i][j] = new_max;
                prev[i][j] = new_prev;
            }
        }
    }
    #if DEBUG
    cout << endl;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            cout << prev[i][j].first << ", " << prev[i][j].second << "   ";
        }
        cout << endl;
    }
    cout << endl;
    #endif // DEBUG
    vector <int> answer;
    int i = n, j = m;
    while (i > 0 || j > 0) {
        auto [x, y] = prev[i][j];
        if (dp[i][j] == dp[x][y]) {
            ///
        } else {
            answer.push_back(a[i - 1]);
        }
        i = x;
        j = y;
    }
    reverse(answer.begin(), answer.end());
    for (auto&& i : answer) {
        cout << i << ' ';
    }
    return 0;
}

/**

https://coderun.yandex.ru/problem/nop-with-response-recovery?currentPage=1&pageSize=20&search=

**/