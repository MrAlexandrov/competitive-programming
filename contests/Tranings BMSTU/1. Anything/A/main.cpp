#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 7;
int n, k;
vector <int> g[MAXN];
vector <int> sz(MAXN, 0);
vector <int> depth(MAXN, 0);
vector <int> val(MAXN);
ll ans = 0;

int DFS(int v, int from = 0) {
    sz[v] = 1;
    for (int to : g[v]) {
        if (to == from) continue;
        depth[to] = depth[v] + 1;
        sz[v] += DFS(to, v);
    }
    val[v] = sz[v] - 1 - depth[v];
    return sz[v];
}

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n >> k;
    k = n - k;
    for (int i = 0; i < n - 1; ++i) {
        int v, u;
        cin >> v >> u;
        --v, --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    DFS(0);
    /*cout << "sz:\t";
    for (int i = 0; i < n; ++i) {
        cout << sz[i] << ' ';
    }
    cout << endl;
    cout << "depth:\t";
    for (int i = 0; i < n; ++i) {
        cout << depth[i] << ' ';
    }
    cout << endl;
    cout << "val:\t";
    for (int i = 0; i < n; ++i) {
        cout << val[i] << ' ';
    }
    cout << endl;*/
    nth_element(val.begin(), val.begin() + k, val.begin() + n, cmp);
    for (int i = 0; i < k; ++i) {
        ans += val[i];
    }
    cout << ans;
    return 0;
}

/**


**/
