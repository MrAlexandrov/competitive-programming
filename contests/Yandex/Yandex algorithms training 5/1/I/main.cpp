#include <bits/stdc++.h>
using namespace std;

//#define DEBUGE 0

int n, year;

int days_in_year = 365;

vector <int> days_in_month {
    31,
    28,
    31,
    30,
    31,
    30,
    31,
    31,
    30,
    31,
    30,
    31
};

int days_in_week = 7;
int month_in_year = 12;

vector <string> month_sting = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

enum months {
    January,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

vector <string> week_string {
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday"
};

struct weekend {
    int day;
    int month;

    friend istream& operator >> (istream& in, weekend& item) {
        string name_month;
        in >> item.day >> name_month;
        --item.day;
        for (int i = 0; i < month_in_year; ++i) {
            if (name_month == month_sting[i]) {
                item.month = i;
                break;
            }
        }
        return in;
    }
};

vector <weekend> weekends;
string first_day;

vector <int> number_weekdays_in_year(days_in_week, 0);
vector <int> count_weekends(days_in_week, 0);

bool check_leap(int year) {
    return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

int number_first_day;

int get_number_day(const weekend& current) {
    int result = current.day;
    for (int i = 0; i < current.month; ++i) {
        result += days_in_month[i];
    }
    return result;
}

int get_weekday(weekend current) {
    return (get_number_day(current) + number_first_day) % days_in_week;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    cin >> n;
    cin >> year;
    if (check_leap(year)) {
        ++days_in_year;
        ++days_in_month[1];
    }
    weekends.reserve(n);
    for (int i = 0; i < n; ++i) {
        weekend x;
        cin >> x;
        weekends.push_back(x);
    }
    cin >> first_day;

    for (number_first_day = 0; number_first_day < 7 && week_string[number_first_day] != first_day; ++number_first_day) {}

    for (int i = number_first_day,
         added_days = days_in_year % days_in_week,
         temp = days_in_year / days_in_week;
         i < number_first_day + days_in_week;
         ++i, --added_days)
    {
        int num = i % days_in_week;
        number_weekdays_in_year[num] = temp + static_cast<bool>(added_days > 0);
    }

    for (int i = 0; i < n; ++i) {
        ++count_weekends[get_weekday(weekends[i])];
    }
    #if DEBUGE
    for (int i = 0; i < n; ++i) {
        cout << get_number_day(weekends[i]) << ' ' << get_weekday(weekends[i]) << endl;
    }
    cout << endl;

    for (int i : count_weekends) {
        cout << i << '\t';
    }
    cout << endl;

    for (int i : number_weekdays_in_year) {
        cout << i << '\t';
    }
    cout << endl;
    #endif // DEBUGE

    vector <int> number_off_days(days_in_week, 0);
    for (int i = 0; i < days_in_week; ++i) {
        number_off_days[i] = number_weekdays_in_year[i] + (n - count_weekends[i]);
        #if DEBUGE
        cout << number_off_days[i] << '\t';
        #endif // DEBUGE
    }
    #if DEBUGE
    cout << endl;
    #endif // DEBUGE

    auto ans_max_weekends = max_element(number_off_days.cbegin(), number_off_days.cend());
    auto ans_min_weekends = min_element(number_off_days.cbegin(), number_off_days.cend());

    cout << week_string[ans_max_weekends - number_off_days.cbegin()] << ' ';
    cout << week_string[ans_min_weekends - number_off_days.cbegin()];
    return 0;
}

/**


**/
