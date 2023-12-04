#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

const int N = 1e2 + 7;
const int INF = 1e9 + 7;

int n, s, f, k;
vector <pair <int, pii>> g[N];
vector <int> times(N, INF);

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n >> s >> f;
    --s, --f;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int v, tin, u, tout;
        cin >> v >> tin >> u >> tout;
        --v, --u;
        g[v].push_back({u, {tin, tout}});
    }
    times[s] = 0;
    set <pii> q;
    q.insert({times[s], s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto [u, time] : g[v]) {
            int tin = time.first;
            int tout = time.second;
            if (tin < times[v] || times[u] <= tout) continue;
            q.erase({times[u], u});
            times[u] = tout;
            q.insert({times[u], u});
        }
    }
    cout << (times[f] == INF ? -1 : times[f]);
    return 0;
}

/**


**/
