#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

void gen(int open_round, int close_round, int open_square, int close_square, stack <char> &opened, string &cur) {
    if (open_round + close_round + open_square + close_square == 2 * n) {
        cout << cur << '\n';
    }
    if (open_round + open_square < n) {
        opened.push('(');
        cur += '(';
        gen(open_round + 1, close_round, open_square, close_square, opened, cur);
        opened.pop();
        cur.pop_back();

        opened.push('[');
        cur += '[';
        gen(open_round, close_round, open_square + 1, close_square, opened, cur);
        opened.pop();
        cur.pop_back();
    }
    if (open_round > close_round || open_square > close_square) {
        if (opened.top() == '(') {
            opened.pop();
            cur += ')';
            gen(open_round, close_round + 1, open_square, close_square, opened, cur);
            opened.push('(');
            cur.pop_back();
        } else {
            opened.pop();
            cur += ']';
            gen(open_round, close_round, open_square, close_square + 1, opened, cur);
            opened.push('[');
            cur.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n;
    if (n & 1) {
        return 0;
    }
    n >>= 1;
    stack <char> opened;
    string cur;
    gen(0, 0, 0, 0, opened, cur);
    return 0;
}

/**


**/
