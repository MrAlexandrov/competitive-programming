#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string height, type;
int cnt = 0;

void nxt() {
    cin >> height >> type;
}

void ask(int x) {
    cnt++;
    cout << "? " << x << endl;
}

void ans(int x) {
    cout << "! " << x << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ask(0);
    nxt();
    int add = 0;
    int sum = 0;
    if (type == "side") {
        add = 18 / 2;
        ask(-add);
        nxt();
        sum -= add;
    } else {
        add = 36 / 2;
        ask(add);
        nxt();
        sum += add;
    }
    while (add > 1) {
        add /= 2;
        if (type == "side") {
            ask(-add);
            nxt();
            sum -= add;
        } else {
            ask(add);
            nxt();
            sum += add;
        }
    }
    if (type == "main") {
        if (height == "low") {
            ans(35 - sum);
        } else {
            ans(36 - sum);
        }
    } else {
        if (height == "low") {
            ans(37 - sum);
        } else {
            ans(38 - sum);
        }
    }
    return 0;
}

/**


**/
