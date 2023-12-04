#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    string s;
    cin >> s;
    int n = s.size();

    map <int, vector <int>> Y_pos;
    string Yandex = "Yandex";
    int Yandex_size = Yandex.size();

    map <int, vector <int>> C_pos;
    string Cup = "Cup";
    int Cup_size = Cup.size();

    for (int i = 0; i < n - Yandex_size + 1; ++i) {
        int cnt = 0;
        for (int j = i; j < i + Yandex_size; ++j) {
            cnt += s[j] != Yandex[j - i];
        }
        Y_pos[cnt].push_back(i);
    }

    for (int i = 0; i < n - Cup_size + 1; ++i) {
        int cnt = 0;
        for (int j = i; j < i + Cup_size; ++j) {
            cnt += s[j] != Cup[j - i];
        }
        C_pos[cnt].push_back(i);
    }

    int ans = 9;
    int y = 0, c = 6;
    /**
    for (auto i : Y_pos) {
        cout << i.first << endl;
        cout << i.second[0] << ' ' << i.second.back() << endl << endl;
    }
    for (auto j : C_pos) {
        cout << j.first << endl;
        cout << j.second[0] << ' ' << j.second.back() << endl << endl;
    }
    **/
    for (auto i : Y_pos) {
        for (auto j : C_pos) {
            if (i.second.empty() || j.second.empty()) continue;
            if (i.first + j.first < ans) {
                ///cout << i.first << ' ' << j.first << endl;
                if (i.second[0] + Yandex_size <= j.second[0]) {
                    ans = i.first + j.first;
                    y = i.second[0], c = j.second[0];
                    continue;
                }
                if (i.second[0] + Yandex_size <= j.second.back()) {
                    ans = i.first + j.first;
                    y = i.second[0], c = j.second.back();
                    continue;
                }
                if (i.second.back() + Yandex_size <= j.second[0]) {
                    ans = i.first + j.first;
                    y = i.second.back(), c = j.second[0];
                    continue;
                }
                if (i.second.back() + Yandex_size <= j.second.back()) {
                    ans = i.first + j.first;
                    y = i.second.back(), c = j.second.back();
                    continue;
                }
            }
        }
    }
    for (int i = 0; i < Yandex_size; ++i) {
        s[y + i] = Yandex[i];
    }
    for (int i = 0; i < Cup_size; ++i) {
        s[c + i] = Cup[i];
    }
    cout << s;
    return 0;
}

/**


**/
