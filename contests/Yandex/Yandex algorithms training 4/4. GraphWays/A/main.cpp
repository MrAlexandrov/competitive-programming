#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 7;
const int INF = 1e9 + 7;
int n, s, f;
vector <pair <int, int>> g[N];
vector <int> d(N, INF);

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
    q.insert({d[s], s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto [to, len] : g[v]) {
            //cout << to << ' ' << len << endl;
            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                q.insert({d[to], to});
            }
        }
        /*for (int i = 0; i < n; ++i) {
            cout << (d[i] == INF ? -1 : d[i]) << ' ';
        }
        cout << endl;*/
    }
    cout << (d[f] == INF ? -1 : d[f]);
    return 0;
}

/**


**/
