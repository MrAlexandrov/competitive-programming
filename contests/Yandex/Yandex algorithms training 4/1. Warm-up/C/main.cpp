#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

const ld inf = 1e100;
const ld eps = 1e-9;
const ld PI = acos((ld)-1.0);
int sign(ld x) { ld (x > eps) - (x < -eps); }

struct PT {
    ld x, y;
    PT() { x = 0, y = 0; }
    PT(ld x, ld y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y)    {}
    PT operator + (const PT &a) const { return PT(x + a.x, y + a.y); }
    PT operator - (const PT &a) const { return PT(x - a.x, y - a.y); }
    PT operator * (const ld a) const { return PT(x * a, y * a); }
    friend PT operator * (const ld &a, const PT &b) { return PT(a * b.x, a * b.y); }
    PT operator / (const ld a) const { return PT(x / a, y / a); }
    bool operator == (PT a) const { return sign(a.x - x) == 0 && sign(a.y - y) == 0; }
    bool operator != (PT a) const { return !(*this == a); }
    bool operator < (PT a) const { return sign(a.x - x) == 0 ? y < a.y : x < a.x; }
    bool operator > (PT a) const { return sign(a.x - x) == 0 ? y > a.y : x > a.x; }
    ld norm() { return sqrt(x * x + y * y); }
    ld norm2() { return x * x + y * y; }
    PT perp() { return PT(-y, x); }
    ld arg() { return atan2(y, x); }
    PT truncate(ld r) { // returns a vector with norm r and having same direction
        ld k = norm();
        if (!sign(k)) return *this;
        r /= k;
        return PT(x * r, y * r);
    }
    friend ostream& operator << (ostream& out, PT &p) {
        return out << p.x << ' ' << p.y;
    }
    friend istream& operator >> (istream& in, PT& p) {
        in >> p.x >> p.y;
        return in;
    }
};

inline ld dot(PT a, PT b) { return a.x * b.x + a.y * b.y; }
inline ld dist2(PT a, PT b) { return dot(a - b, a - b); }
inline ld dist(PT a, PT b) { return sqrt(dot(a - b, a - b)); }
inline ld cross(PT a, PT b) { return a.x * b.y - a.y * b.x; }
inline ld cross2(PT a, PT b, PT c) { return cross(b - a, c - a); }
inline int orientation(PT a, PT b, PT c) { return sign(cross(b - a, c - a)); }
PT perp(PT a) { return PT(-a.y, a.x); }
PT rotateccw90(PT a) { return PT(-a.y, a.x); }
PT rotatecw90(PT a) { return PT(a.y, -a.x); }
PT rotateccw(PT a, ld t) { return PT(a.x * cos(t) - a.y * sin(t), a.x * sin(t) + a.y * cos(t)); }
PT rotatecw(PT a, ld t) { return PT(a.x * cos(t) + a.y * sin(t), -a.x * sin(t) + a.y * cos(t)); }
ld SQ(ld x) { return x * x; }
ld rad_to_deg(ld r) { return (r * 180.0 / PI); }
ld deg_to_rad(ld d) { return (d * PI / 180.0); }
ld get_angle(PT a, PT b) {
    ld costheta = dot(a, b) / a.norm() / b.norm();
    return acos(max((ld)-1.0, min((ld)1.0, costheta)));
}
bool is_point_in_angle(PT b, PT a, PT c, PT p) { // does point p lie in angle <bac
    assert(orientation(a, b, c) != 0);
    if (orientation(a, c, b) < 0) swap(b, c);
    return orientation(a, c, p) >= 0 && orientation(a, b, p) <= 0;
}
bool half(PT p) {
    return p.y > 0.0 || (p.y == 0.0 && p.x < 0.0);
}
void polar_sort(vector<PT> &v) { // sort points in counterclockwise
    sort(v.begin(), v.end(), [](PT a,PT b) {
        return make_tuple(half(a), 0.0, a.norm2()) < make_tuple(half(b), cross(a, b), b.norm2());
    });
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cout.precision(20);
    cout.fixed;
    PT a, b;
    cin >> a >> b;
    ld ans_center = a.norm() + b.norm();

    if (a.norm() > b.norm()) {
        swap(a, b);
    }
    ld line = b.norm() - a.norm();
    ld rad = get_angle(a, b) * a.norm();
    cout << min(ans_center, rad + line);
    return 0;
}

/**


**/
