#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int days_in_year = 365;
const int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int sum_days[13]; // „исло дней в первых i мес€цах
const int hours_in_day = 24;
const int mins_in_hour = 60;
const int secs_in_min = 60;
const int secs_in_day = hours_in_day * mins_in_hour * secs_in_min;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int sum = 0;
    sum_days[0] = 0;
    for (int i = 1; i < 13; ++i) {
        sum += days_in_month[i - 1];
        sum_days[i] = sum;
    }
    int year1, month1, day1, hour1, min1, sec1;
    cin >> year1 >> month1 >> day1 >> hour1 >> min1 >> sec1;
    --month1, --day1;
    int days1 = year1 * days_in_year + sum_days[month1] + day1;
    int secs1 = (hour1 * mins_in_hour + min1) * secs_in_min + sec1;

    int year2, month2, day2, hour2, min2, sec2;
    cin >> year2 >> month2 >> day2 >> hour2 >> min2 >> sec2;
    --month2, --day2;
    int days2 = year2 * days_in_year + sum_days[month2] + day2;
    int secs2 = (hour2 * mins_in_hour + min2) * secs_in_min + sec2;

    int days = days2 - days1;
    int secs = secs2 - secs1;
    if (secs < 0) {
        days--;
        secs += secs_in_day;
    }
    cout << days << ' ' << secs;
    return 0;
}

/**


**/
