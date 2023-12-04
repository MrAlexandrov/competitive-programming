#include <bits/stdc++.h>
using namespace std;

const double INF = 1e9 + 7;
const short N = 2e3 + 7;

vector <pair <short, double>> g[N];
int dist[N];
short T[N];
short V[N];
double ans[N];
short parent[N];
short speed[N];

int n;

void DFS(short v, short from) {
    for (auto [to, len] : g[v]) {
        if (to == from) continue;
        dist[to] = dist[v] + len;
        DFS(to, v);
    }
}

bool cmp(const short &i, const short &j) {
    return V[i] > V[j];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cout.precision(8);
    cin >> n;
    for (short i = 0; i < n; ++i) {
        cin >> T[i] >> V[i];
        speed[i] = i;
    }
    sort(speed, speed + n, cmp);
    for (short i = 0; i < n - 1; ++i) {
        short v, u, s;
        cin >> v >> u >> s;
        --v, --u;
        g[v].push_back({u, s});
        g[u].push_back({v, s});
    }
    ans[0] = 0;
    for (short i = 1; i < n; ++i) {
        ans[i] = INF;
    }
    parent[0] = -1;
    for (short i = 0; i < n; ++i) {
        short from = speed[i];
        dist[from] = 0;
        DFS(from, from);
        ans[from] = min(ans[from], (double)T[from] + (double)dist[0] / V[from]);
        for (short j = 0; j < i; ++j) {
            short to = speed[j];
            if (V[from] >= V[to]) break;
            double new_ans = (double)T[from] + (double)dist[to] / V[from] + ans[to];
            if (new_ans < ans[from]) {
                ans[from] = new_ans;
                parent[from] = to;
            }
        }
    }
    double res = 0;
    short ind = 0;
    for (short i = 0; i < n; ++i) {
        if (res < ans[i]) {
            res = ans[i];
            ind = i;
        }
    }
    cout << fixed << res << '\n';
    while (ind != -1) {
        cout << ind + 1 << ' ';
        ind = parent[ind];
    }
    return 0;
}

/**


**/
