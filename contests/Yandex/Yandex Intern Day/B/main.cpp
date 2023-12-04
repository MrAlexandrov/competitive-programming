#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2222 + 7;
const int INF = INT_MAX;

int n;

vector <pair <int, int>> g[N];
vector <bool> was(N, false);
vector <int> d(N, INF);
int ind = 0;

vector <bool> was1(N, false);

void DFS1(int v, int p) {
    was1[v] = true;
    for (auto [u, c] : g[v]) {
        if (u == p || was1[u]) continue;
        d[u] = min(d[u], d[v] + c);
        DFS1(u, v);
    }
}

pair <int, int> ans = {0, 0};
int mn = INF;

void DFS(int v) {
    was[v] = true;
    for (auto [u, c] : g[v]) {
        if (was[u]) continue;
        for (int i = 0; i < N; ++i) {
            was1[i] = false;
            d[i] = INF;
        }
        d[v] = 0;
        d[u] = 0;
        DFS1(u, v);
        DFS1(v, u);
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            mx = max(mx, d[i]);
        }
        if (mx < mn) {
            mn = mx;
            ans = {v, u};
        }
        DFS(u);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    for (int i = 0; i < n; ++i) {
        DFS(i);
    }
    cout << mn;
    return 0;
}

/**


**/
