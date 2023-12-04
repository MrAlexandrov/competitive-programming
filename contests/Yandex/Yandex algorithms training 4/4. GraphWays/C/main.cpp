#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 7;
const ll INF = 1e12 + 7;
int n, k, s, f;
vector <pair <int, int>> g[N];
vector <ll> d(N, INF);

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int v, u, l;
        cin >> v >> u >> l;
        --v, --u;
        g[v].push_back({u, l});
        g[u].push_back({v, l});
    }
    cin >> s >> f;
    --s, --f;
    set <pair <ll, int>> q;
    d[s] = 0;
    q.insert({d[s], s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto [to, len] : g[v]) {
            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                q.insert({d[to], to});
            }
        }
    }
    cout << (d[f] == INF ? -1 : d[f]);
    return 0;
}

/**


**/
