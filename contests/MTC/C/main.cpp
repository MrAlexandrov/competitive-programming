#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;

/** Варианты разбиений числа в формате:
nums[7] = {
2 2 3
2 3 2
2 5
3 2 2
3 4
4 3
5 2
7
}
**/
vector <deque <int>> nums[15];

void komposition(int x) {
    for (int i = 2; i <= x - 2; ++i) {
        if (nums[i].empty()) {
            komposition(i);
        }
        if (x - i > 2 && nums[x - i].empty()) {
            komposition(x - i);
        }
        for (const auto &j : nums[x - i]) {
            nums[x].push_back(j);
            nums[x].back().push_front(i);
        }
    }
    nums[x].push_back({x});
}

void print(const deque <int> &x) {
    int ptr = 0;/*
    for (int i = 0; i < x.size(); ++i) {
        cout << x[i] << ' ';
    }
    cout << endl;
    return;*/
    int mx = 0;
    int ind = 0;
    int n = x.size();
    deque <char> viv[n];
    for (int i = 0; i < n; ++i) {
        if (x[i] > mx) {
            mx = x[i];
            //ind = i;
        }
    }
    int current_max_len = 0;

    for (int i = 0; i < n; ++i) {
        //cout << i << endl;
        if (i & 1) {
            for (int j = 0; j < x[i]; ++j) {
                viv[i].push_front(s[ptr++]);
            }
            for (int j = x[i]; j < viv[i - 1].size(); ++j) {
                viv[i].push_front('.');
            }
            int cnt = x[i] - viv[i - 1].size();
            if (cnt > 0) {
                for (int j = i - 1; j >= 0; --j) {
                    for (int k = 0; k < cnt; ++k) {
                        viv[j].push_front('.');
                    }
                }
            }
        } else {
            int j = 0;
            if (i > 0) {
                while (viv[i - 1][j] == '.') {
                    viv[i].push_back('.');
                    ++j;
                }
                j = 0;
            }
            for (; j < x[i]; ++j) {
                viv[i].push_back(s[ptr++]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (const char &j : viv[i]) {
            cout << j;
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.txt", "r", stdin);
    ///freopen("input.txt", "w", stdout);
    cin >> s;
    int n = s.size();
    komposition(n);/*
    for (int i = 0; i <= n; ++i) {
        cout << i << ": " << endl;
        for (auto j : nums[i]) {
            for (int k : j) {
                cout << k << ' ';
            }
            cout << endl;
        }
        cout << endl << endl;
    }*/
    for (const auto &i : nums[n]) {
        print(i);
    }
    return 0;
}

/**
abcdefghijklnm

**/
