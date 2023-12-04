#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e2 + 7;
const ll INF = INT_MAX;

struct edge {
    int to = 0;
    int time = 0;
    int cup = 0;
    edge() {}
    edge(int _to, int _time, int _cup) : to(_to), time(_time), cup(_cup) {}
};

vector <edge> g[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, t, w;
        cin >> u >> v >> t >> w;
        --u, --v;
        w -= 3e6;
        if (w < 0) continue;
        w /= 100;
        g[u].push_back(edge(v, t, w));
        g[v].push_back(edge(u, t, w));
    }
    ll l = 0, r = 1e7 + 1;
    vector <int> delivery(n, INF);
    set <pair <int, int>> q;
    while (r - l > 1) {
        for (int i = 0; i < n; ++i) {
            delivery[i] = INF;
        }
        q.clear();
        ll m = (l + r) / 2;
        delivery[0] = 0;
        q.insert({delivery[0], 0});
        while (!q.empty()) {
            auto [current_time, current_node] = *q.begin();
            q.erase(q.begin());
            for (auto [to, time, cup] : g[current_node]) {
                if (cup < m) continue;
                if (delivery[current_node] + time < delivery[to]) {
                    q.erase({delivery[to], to});
                    delivery[to] = delivery[current_node] + time;
                    q.insert({delivery[to], to});
                }
            }
        }
        if (delivery[n - 1] <= 1440) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l;
    return 0;
}

/**
3 3
2 3 40 3000299
1 3 4 3000056
1 2 10 3000201

**/
