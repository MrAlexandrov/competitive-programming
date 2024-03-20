#include <bits/stdc++.h>
using namespace std;

//#define DEBUGE 1

long double EPS = 1e-10;

long double L;

struct point_on_circle {
    long double position;
    long double velocity;

    point_on_circle& operator += (const long double& time) {
        position += velocity * time;
        while (position > L) {
            position -= L;
        }
        while (position < 0) {
            position += L;
        }
        return *this;
    }
    point_on_circle operator + (const long double& time) const {
        point_on_circle result = *this;
        result += time;
        return result;
    }
};

int sign(const long double &x) {
    return (x > EPS) - (x < -EPS);
}

struct PT {
    long double x = 0;
    long double y = 0;
    PT() {}
    PT(long double x, long double y) : x(x), y(y) {}
    PT(const PT& p) : x(p.x), y(p.y)    {}
    PT operator + (const PT &a) const { return PT(x + a.x, y + a.y); }
    PT operator - (const PT &a) const { return PT(x - a.x, y - a.y); }
    PT operator * (const long double& a) const { return PT(x * a, y * a); }
    friend PT operator * (const long double& a, const PT& b) { return PT(a * b.x, a * b.y); }
    PT operator / (const long double& a) const { return PT(x / a, y / a); }
    bool operator == (const PT& a) const { return sign(a.x - x) == 0 && sign(a.y - y) == 0; }
    bool operator != (const PT& a) const { return !(*this == a); }
    bool operator < (const PT& a) const { return sign(a.x - x) == 0 ? y < a.y : x < a.x; }
    bool operator > (const PT& a) const { return sign(a.x - x) == 0 ? y > a.y : x > a.x; }
    long double norm() const { return sqrt(x * x + y * y); }
    long double norm2() const { return x * x + y * y; }
    PT perp() const { return PT(-y, x); }
    long double arg() const { return atan2(y, x); }
    PT truncate(long double& r) const { // returns a vector with norm r and having same direction
        long double k = norm();
        if (!sign(k)) return *this;
        r /= k;
        return PT(x * r, y * r);
    }
    friend ostream& operator << (ostream& out, const PT &p) {
        return out << p.x << ' ' << p.y;
    }
    friend istream& operator >> (istream& in, PT& p) {
        in >> p.x >> p.y;
        return in;
    }
};

long double cross(const PT& a, const PT& b) {
    return a.x * b.y - a.y * b.x;
}
long double cross2(const PT& a, const PT& b, const PT& c) {
    return cross(b - a, c - a);
}

// intersection point between ab and cd assuming unique intersection exists
bool line_line_intersection(const PT& a, const PT& b, const PT& c, const PT& d, PT &ans) {
    long double a1 = a.y - b.y, b1 = b.x - a.x, c1 = cross(a, b);
    long double a2 = c.y - d.y, b2 = d.x - c.x, c2 = cross(c, d);
    long double det = a1 * b2 - a2 * b1;
    if (det == 0) return false;
    ans = PT((b1 * c2 - b2 * c1) / det, (c1 * a2 - a1 * c2) / det);
    return true;
}

istream& operator >> (istream& in, point_on_circle& item) {
    in >> item.position >> item.velocity;
    return in;
}

point_on_circle first, second;

long double dist(const point_on_circle& a, const point_on_circle& b) {
    return min(max(a.position, b.position) - min(a.position, b.position),
               L - max(a.position, b.position) + min(a.position, b.position));
}

long double forward_dist(const point_on_circle& a, const long double& b) {
    if (a.velocity > 0) {
        return (b >= a.position ? b - a.position : L - (a.position - b));
    } else {
        return (b <= a.position ? a.position - b : L - (b - a.position));
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    setprecision(20);
    cout.fixed;
    cin >> L;
    cin >> first >> second;
    if (fabs(first.velocity) < fabs(second.velocity)) {
        swap(first, second);
    }
    point_on_circle zero{0.0, 0.0};
    if (dist(zero, first) == dist(zero, second)) {
        cout << "YES\n";
        cout << 0;
        return 0;
    }
    if (!first.velocity && !second.velocity) {
        cout << "NO";
        return 0;
    }
    long double full_circle = (long double)L / fabs(first.velocity);
    long double half_circle = full_circle / 2.0;

    vector <long double> times;
    times.push_back(0);
    if (first.velocity) {
        times.push_back(forward_dist(first, L / 2.0) / fabs(first.velocity));
        times.push_back(forward_dist(first, 0.0) / fabs(first.velocity));
    }
    if (second.velocity) {
        times.push_back(forward_dist(second, L / 2.0) / fabs(second.velocity));
        times.push_back(forward_dist(second, 0) / fabs(second.velocity));
    }

    times.push_back(full_circle);
    #if DEBUGE
    cout << "times: " << endl;
    for (auto i : times) {
        cout << i << endl;
    }
    cout << "end times" << endl;
    #endif // DEBUGE
    sort(times.begin(), times.end());

    long double time_ans = 0;

    for (int i = 0; i < times.size() - 1; ++i) {
        PT check;
        #if DEBUGE
        cout << "times[i] = " << times[i] << endl;
        cout << "dist(zero, (first + times[i])) = " << dist(zero, (first + times[i])) << endl;
        cout << "dist(zero, (second + times[i])) = " << dist(zero, (second + times[i])) << endl;

        cout << "times[i + 1] = " << times[i + 1] << endl;
        cout << "dist(zero, (first + times[i + 1])) = " << dist(zero, (first + times[i + 1])) << endl;
        cout << "dist(zero, (second + times[i + 1])) = " << dist(zero, (second + times[i + 1])) << endl;
        #endif // DEBUGE
        if (line_line_intersection(PT(times[i],     dist(zero, (first + times[i]))      ),
                                   PT(times[i + 1], dist(zero, (first + times[i + 1]))  ),
                                   PT(times[i],     dist(zero, (second + times[i]))     ),
                                   PT(times[i + 1], dist(zero, (second + times[i + 1])) ),
                                   check))
        {
            assert(times[i] >= EPS || times[i] == 0.0);
            if (times[i] <= check.x && check.x <= times[i + 1]) {
                /*long double l = max(max(static_cast<long double>(0), times[i]), check.x - static_cast<long double>(1e-3));
                long double r = min({times[i + 1], check.x + static_cast<long double>(1e-3)});
                while (r - l > EPS) {
                    long double ml = (l + l + r) / 3.0;
                    long double mr = (l + r + r) / 3.0;
                    if (
                        fabs(dist(zero, (first + ml)) - dist(zero, (second + ml))) <
                        fabs(dist(zero, (first + mr)) - dist(zero, (second + mr)))
                        )
                    {
                        l = ml;
                    } else {
                        r = mr;
                    }
                }
                check.x = l;*/
                cout << "YES\n";
                assert(check.x >= EPS);
                cout << setprecision(20) << fixed << check.x << endl;
                return 0;
            }
        }
    }
    return 0;
}

/**
10 1 1 9 -1

0


1000 0 -1000000 1 100


**/
