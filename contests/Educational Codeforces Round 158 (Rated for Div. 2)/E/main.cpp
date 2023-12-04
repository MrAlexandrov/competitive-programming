#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 7;
vector <int> g[N];

void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int &i : a) {
        cin >> i;
    }
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/**
Изначально вклад дают вершины, степень которых не равна 0

1-м действием мы можем удалять только листья, таким образом, сумма уменьшается на величину листа, и увеличивается на
величину следующей вершины, если она могла не войти в ответ

**/

