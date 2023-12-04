#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 7;

struct sqrt_decomposition {
    int n;
    const int K = 315;
    vector <int> a;
    vector <int> block;
    sqrt_decomposition(vector <int> &_a) : n(_a.size()) {
        a = _a;
        block.resize(n / K + 7, 0);
        build(a);
    }
    void build(const vector <int> &a) {
        for (int l = 0; l < n; l += K) {
            int now = 0;
            for (int i = l; i < l + K && i < n; ++i) {
                now = max(now, a[i]);
            }
            block[l / K] = now;
        }
    }
    int get_max(int l, int r) {
        int res = 0;
        while (l < r) {
            if (l % K == 0 && l + K <= r) {
                res = max(res, block[l / K]);
                l += K;
            } else {
                res = max(res, a[l]);
                ++l;
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int &i : a) {
        cin >> i;
    }
    sqrt_decomposition SQD(a);
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int l, r;
        cin >> l >> r;
        --l;
        cout << SQD.get_max(l, r) << ' ';
    }
    return 0;
}

/**
5
2 2 2 1 5
2
2 3
2 5

**/
