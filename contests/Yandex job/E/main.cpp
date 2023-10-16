#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Trie {
    struct node {
        map <int, node*> nxt;
        ll cnt;
        node() {
            cnt = 0;
        }
    } *root;
    Trie() {
        root = new node();
    }
    void insert(vector <int> &x) {
        node* cur = root;
        cur -> cnt++;
        for (int i : x) {
            if (cur -> nxt[i] == NULL) {
                cur -> nxt[i] = new node();
            }
            cur = cur -> nxt[i];
            cur -> cnt++;
        }
    }
    ll DFS(node* v) {
        ll now = (v == root ? 0 : v -> cnt);
        //cout << now << endl;
        ll res = now * (now - 1) / 2;
        for (auto x : v -> nxt) {
            node* u = x.second;
            res += DFS(u);
        }
        return res;
    }
} t;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int n;
    cin >> n;
    vector <int> k(n);
    vector <int> a[n];
    for (int i = 0; i < n; ++i) {
        cin >> k[i];
        a[i].resize(k[i]);
        for (int j = 0; j < k[i]; ++j) {
            cin >> a[i][j];
        }
        t.insert(a[i]);
    }
    cout << t.DFS(t.root);
    return 0;
}

/**
6
7
1 2 1 3 1 2 1
3
1 2 1
3
3 2 1
1
1
3
2 2 1
3
2 3 1

------------------------
1 2 1 3 1 2 1
1 2 1
3 2 1
1
2 2 1
2 3 1
===============
3 1 1
1
**/
