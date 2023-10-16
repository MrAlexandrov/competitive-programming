#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 7;
const int INF = 1e5 + 7;

int n;
vector <int> _a(N);
vector <int> copy_a(N);
int *a = &_a[1];
int answer = 0;

void LIC(vector <vector <int>> &d, vector <vector <int>> &p, int mx, bool les = false) {
    int num = (int)les;
    for (int i = 0; i < n; ++i) {
        d[num][i] = 1;
        p[num][i] = -1;
        if (copy_a[i] == INF || (!les && copy_a[i] > mx || les && copy_a[i] < mx)) continue;
        for (int j = 0; j < i; ++j) {
            if (copy_a[j] == INF || (!les && copy_a[j] > mx || les && copy_a[j] < mx)) continue;
            if (copy_a[j] < copy_a[i]) {
                if (d[num][i] < d[num][j] + 1) {
                    d[num][i] = d[num][j] + 1;
                    p[num][i] = j;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n;
    //int *aa = &_a[1];
    for (int i = 0; i < n; ++i) {
        cin >> _a[i];
    }
    copy_a = _a;
    /*vector <vector <int>> d(2, vector <int> (N, 0));            /// index of last element
    vector <vector <int>> p(2, vector <int> (N, 0));
    LIC(d, p, 5);
    cout << "d : ";
    for (int i = 0; i <= n; ++i) {
        cout << d[0][i] << ' ';
    }
    cout << endl;
    cout << "p : ";
    for (int i = 0; i <= n; ++i) {
        cout << p[0][i] << ' ';
    }
    cout << endl;
    int ans = d[0][0], pos = 0;
    for (int i = 0; i < n; ++i) {
        if (ans < d[0][i]) {
            ans = d[0][i];
            pos = i;
        }
    }
    cout << "ans = " << ans << endl;
    cout << "pos = " << pos << endl;
    vector <int> path;
    while (pos != -1) {
        path.push_back(pos);
        pos = p[0][pos];
    }
    reverse(path.begin(), path.end());
    cout << "path : ";
    for (int i : path) {
        cout << i << ' ';
    }
    cout << endl;*/
    //a[-1] = -INF;
    //a[n] = INF;
    //int max_el = *max_element(_a.begin(), _a.end());
    for (int mx = 0; mx <= 100; ++mx) {
        vector <vector <int>> d(2, vector <int> (N, 0));            /// index of last element
        vector <vector <int>> p(2, vector <int> (N, 0));
        copy_a = _a;
        int now = 0;
        LIC(d, p, mx);
        int ans = d[0][0], pos = 0;
        for (int i = 0; i < n; ++i) {
            if (ans < d[0][i]) {
                ans = d[0][i];
                pos = i;
            }
        }
        cout << "ans1 = " << ans << endl;
        /*cout << "ans1 = " << ans << endl;
        cout << "pos = " << pos << endl;
        cout << "d : ";
        for (int i = 0; i <= n; ++i) {
            cout << d[0][i] << ' ';
        }
        cout << endl;
        cout << "p : ";
        for (int i = 0; i <= n; ++i) {
            cout << p[0][i] << ' ';
        }
        cout << endl;*/
        now += ans;
        //vector <int> path;
        while (pos != -1) {
            copy_a[pos] = INF;
            //path.push_back(pos);
            pos = p[0][pos];
        }
        /*if (mx == 5) {
            reverse(path.begin(), path.end());
            cout << "path : ";
            for (int i : path) {
                cout << i << ' ';
            }
            cout << endl;
        }*/
        for (int l = 0, r = n - 1; l < r; ++l, --r) {
            swap(copy_a[l], copy_a[r]);
        }
        //cout << "end of first phase" << endl;
        LIC(d, p, mx, true);
        ans = d[1][0], pos = 0;
        for (int i = 0; i < n; ++i) {
            if (ans < d[1][i]) {
                ans = d[1][i];
                pos = i;
            }
        }
        cout << "ans2 = " << ans << endl;
        now += ans;
        /*path.clear();
        while (pos != -1) {
            copy_a[pos] = INF;
            path.push_back(pos);
            pos = p[1][pos];
        }
        if (mx == 5) {
            reverse(path.begin(), path.end());
            cout << "path : ";
            for (int i : path) {
                cout << i << ' ';
            }
            cout << endl;
        }*/
        cout << "mx = " << mx << ", now = " << now << endl;
        answer = max(answer, now);
    }
    /*cout << "ans = " << ans << endl;

    vector <int> path;
    while (pos != -1) {
        path.push_back(pos);
        pos = p[1][pos];
    }
    reverse(path.begin(), path.end());
    cout << "path : ";
    for (int i : path) {
        cout << i << ' ';
    }
    cout << endl;*/
    cout << answer;
    return 0;
}

/**


**/
