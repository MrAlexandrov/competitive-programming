#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 7;
const int INF = 1e9 + 7;
int n, s, f;
vector <pair <int, int>> g[N];
vector <int> d(N, INF);
vector <int> p(N, -1);

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n >> s >> f;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            if (x == -1 || i == j) continue;
            g[i].push_back({j, x});
        }
    }
    --f, --s;
    set <pair <int, int>> q;
    d[s] = 0;
    p[s] = -1;
    q.insert({d[s], s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto [to, len] : g[v]) {
            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
    if (d[f] == INF) {
        cout << -1;
    } else {
        vector <int> ans;
        int ind = f;
        while (ind != -1) {
            ans.push_back(ind);
            ind = p[ind];
        }
        reverse(ans.begin(), ans.end());
        for (const int &i : ans) {
            cout << i + 1 << ' ';
        }
    }
    return 0;
}

/**
3 2 1
0 1 1
4 0 1
2 1 0

**/
