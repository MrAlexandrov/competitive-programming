#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e2 + 30;

ld _prob[21]{};
ld (*prob) = &_prob[10];
ld _work[230][2]{};
ld (*work)[2] = &_work[115];
int ptr = 0;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    cout.precision(20);
    cout.fixed;
    int b;
    cin >> b;

    prob[0] = 0.1;
    work[0][ptr] = 0.1;

    for (int i = 1; i <= 9; ++i) {
        prob[i] = (ld)(10 - i) / 100;
        prob[-i] = prob[i];
        work[i][ptr] = prob[i];
        work[-i][ptr] = prob[i];
    }

    ld ans = 0;

    ld take = 0;
    for (int j = 1; j < 10000; ++j) {                       /// number moves
        if (j > 1) {
            for (int x = -b + 1; x <= b - 1; ++x) {         /// prev diff
                for (int y = -9; y <= 9; ++y) {             /// new move
                    work[x + y][ptr] += work[x][ptr ^ 1] * prob[y];
                }
            }
        }
        take = 0;
        for (int i = -110; i <= 110; ++i) {
            if (-b < i && i < b) continue;
            take += work[i][ptr];
        }
        ans += take * j;
        ptr ^= 1;
        for (int x = -110; x <= 110; ++x) {
            work[x][ptr] = 0;
        }
    }
    cout << ans;
    return 0;
}

/**


**/
