#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair <int, int> get_match() {
    pair <int, int> res;
    char c;
    cin >> c;
    res.first = c - '0';
    cin >> c;
    cin >> c;
    res.second = c - '0';
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    pair <int, int> first_match = get_match();
    pair <int, int> second_match = get_match();
    int num;
    cin >> num;
    int left_team = first_match.first + second_match.first;
    int right_team = first_match.second + second_match.second;
    int ans = 0;
    if (left_team <= right_team) {
        ans = max(0, right_team - left_team);
        if (num == 1) {
            if (second_match.first + ans > first_match.second) {
                ///
            } else {
                ++ans;
            }
        } else {
            if (first_match.first > second_match.second) {
                ///
            } else {
                ++ans;
            }
        }
    }

    cout << ans;
    return 0;
}

/**
0:3
0:2
1

0:3
0:2
2

**/
