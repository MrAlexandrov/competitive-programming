#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e3 + 7;

vector <int> g[N];

struct half {
    vector <int> a[26];
} l, r;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        s[i] -= 'a';
    }/*
    for (int i = 0; i < n; ++i) {
        cout << i << " = " << (char)(s[i] + 'a') << endl;
    }
    cout << endl;*/
    for (int i = 0; i < n; i += 2) {
        l.a[(int)s[i]].push_back(i);
    }
    for (int i = 1; i < n; i += 2) {
        r.a[(int)s[i]].push_back(i);
    }
    for (int i : l.a[0]) {
        cout << i << ' ';
    }
    cout << endl;
    cout << endl;
    for (int i : r.a[0]) {
        cout << i << ' ';
    }
    cout << endl;
    cout << endl;
    cout << endl;//*/
    set <pair <int, int>> edges;
    for (int i = 0; i < 26; ++i) {
        for (const int jj : l.a[i]) {
            for (const int kk : r.a[i]) {
                int j = jj, k = kk;
                if (j > k) {
                    swap(j, k);
                }
                cout << "l " << j << ' ' << k << endl;
                if (j + 1 == k && (j == 0 || j == n - 2) || j == 1 || k == n - 2) {
                    continue;
                }
                edges.insert({k, j});
            }
        }
        for (const int jj : r.a[i]) {
            for (const int kk : l.a[i]) {
                int j = jj, k = kk;
                if (j > k) {
                    swap(j, k);
                }
                cout << "r " << j << ' ' << k << endl;
                if (j + 1 == k && (j == 0 || j == n - 2) || j == 1 || k == n - 2) {
                    continue;
                }
                edges.insert({k, j});
            }
        }
    }
    cout << endl;
    //sort(edges.begin(), edges.end());
    int ans = 0;
    int last = -5000, now = -5000;
    pair <int, int> prev = {-1, -1};
    for (auto &[r, l] : edges) {
        cout << l << ' ' << r << endl;
        if (r + l == prev.first + prev.second) {
            now = (l + r) / 2;
            prev = {l, r};
            ++ans;
            cout << "take " << l << ' ' << r << endl;
            continue;
        }
        last = now;
        if (last < l) {
            if (last + 1 == (l + r) / 2) {
                continue;
            }
            now = (l + r) / 2;
            prev = {l, r};
            ++ans;
            cout << "take " << l << ' ' << r << endl;
            continue;
        }
    }
    cout << ans;
    return 0;
}

/**
abracadabra

ab
racadabra

mtssttsmmt
 (())
   (())
       ()

aaaa

**/
