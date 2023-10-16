#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int check(const string &s) {
    int n = s.size();
    int inc = 1, inc_now = 1;
    int dec = 1, dec_now = 1;
    int equ = 1, equ_now = 1;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i + 1] - s[i] == 1) {
            inc_now++;
        } else {
            inc = max(inc, inc_now);
            inc_now = 1;
        }
        if (s[i] - s[i + 1] == 1) {
            dec_now++;
        } else {
            dec = max(dec, dec_now);
            dec_now = 1;
        }
        if (s[i] == s[i + 1]) {
            equ_now++;
        } else {
            equ = max(equ, equ_now);
            equ_now = 1;
        }
    }
    inc = max(inc, inc_now);
    dec = max(dec, dec_now);
    equ = max(equ, equ_now);

    return max({inc, dec, equ});
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    string s;
    cin >> s;
    vector <string> a;
    vector <string> start(3, s);
    char t;
    for (int i = 0; i < 7; ++i) {
        start[0].push_back((char)min((int)'9', start[0].back() + 1));
        start[1].push_back(start[1].back());
        start[2].push_back((char)max((int)'0', start[2].back() - 1));
    }
    if (start[0] == start[1] && start[1] == start[2]) {
        start[0].back() = '$';
        start[1].back() = '#';
    }
    if (start[0] == start[1]) {
        start[0].back() = '$';
    }
    if (start[0] == start[2]) {
        start[0].back() = '$';
    }
    if (start[1] == start[2]) {
        start[1].back() = '$';
    }
    /*
    for (int i = 0; i < 3; ++i) {
        cout << start[i] << endl;
    }
    cout << endl;*/
    vector <int> num(3);
    for (int i = 0; i < 3; ++i) {
        num[i] = check(start[i]);
    }
    /*
    for (int i = 0; i < 3; ++i) {
        cout << num[i] << endl;
    }
    cout << endl;*/
    int longest = *max_element(num.begin(), num.end());
    int cnt = 0;
    for (int i = 0; i < 3; ++i) {
        cnt += num[i] == longest;
    }
    cout << cnt;
    return 0;
}

/**
8888*******
   01234567
  012345678
 0123456789
   98765432
  987654321
 0987654321
    8888888
**/
