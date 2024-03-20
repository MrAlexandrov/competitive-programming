#include <bits/stdc++.h>
using namespace std;

#define DEBUGE 0

int x, y, p;
int our_soliders;
int barrack;
int rival_soliders;
int ans = 0;

void attack_barrack() {
    if (our_soliders > barrack) {
        int remain_attack = our_soliders - barrack;
        barrack = 0;
        rival_soliders = max(0, rival_soliders - remain_attack);
    } else {
        barrack -= our_soliders;
    }
}

void attack_soliders() {
    if (our_soliders > rival_soliders) {
        int remain_attack = our_soliders - rival_soliders;
        rival_soliders = 0;
        barrack = max(0, barrack - remain_attack);
    } else {
        rival_soliders -= our_soliders;
    }
}

int model_time(int our_soliders, int rival_soliders) {
    if (rival_soliders <= 0) return 0;
    int i = 1;
    #if DEBUGE
    cout << our_soliders << ' ' << rival_soliders << endl;
    #endif // DEBUGE
    while (our_soliders > 0 && rival_soliders > 0) {
        if (i & 1) {
            our_soliders -= rival_soliders;
        } else {
            rival_soliders -= our_soliders;
        }
        ++i;
        #if DEBUGE
        cout << our_soliders << ' ' << rival_soliders << endl;
        #endif // DEBUGE
    }
    if (our_soliders <= 0) return -1;
    return (i + 1) / 2;
}

struct event {
    int our_soliders;
    int barrack;
    int rival_soliders;
};

ostream& operator << (ostream& out, const event& item) {
    out << item.our_soliders << ' ' << item.barrack << ' ' << item.rival_soliders;
    return out;
}

vector <event> game;

bool make_move() {
    if (barrack <= 0 && rival_soliders <= 0) return false;
    ++ans;

    //int remain_attack_for_barrack = (our_soliders > rival_soliders ? our_soliders - rival_soliders : 0);
    //int remain_attack_for_soliders = (our_soliders > barrack ? our_soliders - barrack : 0);

    //int check = model_time(our_soliders - (rival_soliders - remain_attack_for_soliders), rival_soliders - remain_attack_for_soliders);
    //if (our_soliders >= barrack && check != -1 && false) {
    //    attack_barrack();
    //} else {
        attack_soliders();
    //}
    if (rival_soliders > 0) {
        our_soliders = max(0, our_soliders - rival_soliders);
    }
    if (barrack > 0) {
        rival_soliders += p;
    }
    #if DEBUGE
    cout << our_soliders << ' ' << barrack << ' ' << rival_soliders << endl;
    #endif // DEBUGE
    game.push_back(event{our_soliders, barrack, rival_soliders});
    return (our_soliders > 0) && (barrack > 0 || rival_soliders > 0);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    cin >> x >> y >> p;

    our_soliders = x;
    barrack = y;
    rival_soliders = 0;
    for (int i = 0; i < x + y + p && make_move(); ++i) {}
    #if DEBUGE
    for (int i = 0; i < game.size(); ++i) {
        cout << game[i] << endl;
    }
    #endif // DEBUGE
    int prev_our_soliders = our_soliders;
    int prev_barrack = barrack;
    int prev_rival_soliders = rival_soliders;

    if (our_soliders > 0 && (barrack > 0 || rival_soliders > 0)) {
        make_move();
    }

    /*if (our_soliders <= 0 || barrack > 0 || rival_soliders > 0) {
        cout << -1;
        return 0;
    }*/

    int l = 0, r = game.size();
    #if DEBUGE
    cout << "game.size(): " << r << endl;
    #endif // DEBUGE
    for (; (game[l].our_soliders < game[l].barrack); ++l) {}

    int answer = INT_MAX;
    for (int i = l; i < r; ++i) {
        bool add = false;
        int remain_rival_soliders = game[i].rival_soliders - (game[i].our_soliders - game[i].barrack);
        if (game[i].rival_soliders > 0 && remain_rival_soliders <= 0) {
            add = true;
        }
        int check = model_time(game[i].our_soliders, remain_rival_soliders);
        if (check == -1) continue;
        answer = min(answer, i + 1 + check + add);
        #if DEBUGE
        cout << "after " << i + 1 << " moves " << game[i] << endl;
        cout << check + add << endl << endl << endl;
        #endif // DEBUGE
    }

    cout << (answer == INT_MAX ? -1 : answer);
    return 0;
}

#undef DEBUGE

/**
10 11 15

1
10 11 0
10  1 0
10  1 15

2
10  0 6
4   0 6

3
4   0 2
2   0 2

4
2   0 0


250
500
230
250 230 230
250 210 230
250 190 230
250 170 230
250 150 230
250 130 230
140 0 110
140 0 0


250 150 230
120 0 130
110 0 10
110 0 0

250 170 230
100 0 150
50 0 50
50 0 0

9
**/
