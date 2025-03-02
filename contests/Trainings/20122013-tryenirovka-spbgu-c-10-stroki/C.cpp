#include <cstddef>
#include <iostream>

#if defined (DEBUG)
#include <numeric>
#endif // DEBUG

#include <vector>
#include <string>
#include <unordered_set>
#include <random>
#include <cassert>

namespace NHash {

namespace {

namespace NModular {

template <typename T>
T Inverse(T a, T m);

template <int Mod>
class TModular final {
public:
    static constexpr int Module = Mod;

    TModular();

    template <typename T>
    TModular(const T&);

    template <typename T>
    static int Normalize(const T&);

    constexpr int operator()() const;

    template <typename T>
    explicit operator T() const;

    constexpr static int GetModule() { return Mod; }

    TModular& operator+=(const TModular& other);
    TModular& operator-=(const TModular& other);
    TModular& operator*=(const TModular& other);
    TModular& operator/=(const TModular& other);

    template <typename T>
    TModular& operator+=(const T& other);
    template <typename T>
    TModular& operator-=(const T& other);
    template <typename T>
    TModular& operator*=(const T& other);
    template <typename T>
    TModular& operator/=(const T& other);

    TModular& operator++();
    TModular& operator--();
    TModular operator++(int);
    TModular operator--(int);
    TModular operator-() const;

    friend const int& abs(const TModular& x);

    template <int T>
    friend std::ostream& operator<<(std::ostream& out, const TModular<T>& number);

private:
    int value;
};

template <int Mod>
TModular<Mod>::TModular() : value(0) {}

template <int Mod>
template <typename T>
TModular<Mod>::TModular(const T& x) : value(Normalize(x)) {}

template <int Mod>
template <typename T>
int TModular<Mod>::Normalize(const T& x) {
    int result = static_cast<int>(x % Mod);
    if (result < 0) result += Mod;
    return result;
}


template <int Mod>
constexpr int TModular<Mod>::operator()() const {
    return value;
}

template <int Mod>
template <typename T>
TModular<Mod>::operator T() const {
    return static_cast<T>(value);
}

template <int Mod>
TModular<Mod>& TModular<Mod>::operator+=(const TModular<Mod>& other) {
    value = Normalize(value + other.value);
    return *this;
}

template <int Mod>
TModular<Mod>& TModular<Mod>::operator-=(const TModular<Mod>& other) {
    value = Normalize(value - other.value);
    return *this;
}

template <int Mod>
TModular<Mod>& TModular<Mod>::operator*=(const TModular<Mod>& other) {
    value = (static_cast<long long>(value) * other.value) % Mod;
    return *this;
}

template <int Mod>
TModular<Mod>& TModular<Mod>::operator/=(const TModular<Mod>& other) {
    if (other.value == 0) {
        throw std::runtime_error("Division by zero in modular arithmetic");
    }
    value = (value * Inverse(other.value, Mod)) % Mod;
    return *this;
}



template <int Mod>
template <typename T>
TModular<Mod>& TModular<Mod>::operator+=(const T& other) {
    return *this += TModular(other);
}

template <int Mod>
template <typename T>
TModular<Mod>& TModular<Mod>::operator-=(const T& other) {
    return *this -= TModular(other);
}

template <int Mod>
template <typename T>
TModular<Mod>& TModular<Mod>::operator*=(const T& other) {
    return *this *= static_cast<TModular<Mod>>(other);
}

template <int Mod>
template <typename T>
TModular<Mod>& TModular<Mod>::operator/=(const T& other) {
    return *this /= static_cast<TModular<Mod>>(other);
}



template <int Mod>
TModular<Mod> operator+(const TModular<Mod>& lhs, const TModular<Mod>& rhs) {
    TModular<Mod> result = lhs;
    return result += rhs;
}

template <int Mod, typename T>
TModular<Mod> operator+(const TModular<Mod>& lhs, const T& rhs) {
    TModular<Mod> result = lhs;
    return result += TModular<Mod>(rhs);
}

template <int Mod, typename T>
TModular<Mod> operator+(const T& lhs, const TModular<Mod>& rhs) {
    TModular<Mod> result = lhs;
    return result += rhs;
}

template <int Mod>
TModular<Mod> operator-(const TModular<Mod>& lhs, const TModular<Mod>& rhs) {
    TModular<Mod> result = lhs;
    return result -= rhs;
}

template <int Mod, typename T>
TModular<Mod> operator-(const TModular<Mod>& lhs, const T& rhs) {
    TModular<Mod> result = lhs;
    return result -= TModular<Mod>(rhs);
}

template <int Mod, typename T>
TModular<Mod> operator-(const T& lhs, const TModular<Mod>& rhs) {
    TModular<Mod> result = lhs;
    return result -= rhs;
}

template <int Mod>
TModular<Mod> operator*(const TModular<Mod>& lhs, const TModular<Mod>& rhs) {
    TModular<Mod> result = lhs;
    return result *= rhs;
}

template <int Mod, typename T>
TModular<Mod> operator*(const TModular<Mod>& lhs, const T& rhs) {
    TModular<Mod> result = lhs;
    return result *= TModular<Mod>(rhs);
}

template <int Mod, typename T>
TModular<Mod> operator*(const T& lhs, const TModular<Mod>& rhs) {
    TModular<Mod> result = lhs;
    return result *= rhs;
}

template <int Mod>
TModular<Mod> operator/(const TModular<Mod>& lhs, const TModular<Mod>& rhs) {
    TModular<Mod> result = lhs;
    return result /= rhs;
}

template <int Mod, typename T>
TModular<Mod> operator/(const TModular<Mod>& lhs, const T& rhs) {
    TModular<Mod> result = lhs;
    return result /= TModular<Mod>(rhs);
}

template <int Mod, typename T>
TModular<Mod> operator/(const T& lhs, const TModular<Mod>& rhs) {
    TModular<Mod> result = lhs;
    return result /= rhs;
}



template <int Mod>
TModular<Mod>& TModular<Mod>::operator++() {
    return *this += 1;
}

template <int Mod>
TModular<Mod>& TModular<Mod>::operator--() {
    return *this -= 1;
}

template <int Mod>
TModular<Mod> TModular<Mod>::operator++(int) {
    TModular result(*this);
    *this += 1;
    return result;
}

template <int Mod>
TModular<Mod> TModular<Mod>::operator--(int) {
    TModular result(*this);
    *this -= 1;
    return result;
}

template <int Mod>
TModular<Mod> TModular<Mod>::operator-() const {
    return TModular(-value);
}


template <int Mod>
const int& abs(const TModular<Mod>& x) {
    return x();
}

template <int Mod>
bool operator==(const TModular<Mod>& lhs, const TModular<Mod>& rhs) {
    return lhs() == rhs();
}

template <int Mod, typename T>
bool operator==(const TModular<Mod>& lhs, const T& rhs) {
    return lhs() == TModular<Mod>(rhs)();
}

template <int Mod, typename T>
bool operator==(const T& lhs, const TModular<Mod>& rhs) {
    return TModular<Mod>(lhs)() == rhs();
}

template <int Mod>
bool operator!=(const TModular<Mod>& lhs, const TModular<Mod>& rhs) {
    return lhs() != rhs();
}

template <int Mod1, int Mod2>
bool operator!=(const TModular<Mod1>&, const TModular<Mod2>&) {
    return true;
}

template <int Mod>
bool operator<(const TModular<Mod>& lhs, const TModular<Mod>& rhs) {
    return lhs() < rhs();
}

// TODO: add operators

template <int Mod>
TModular<Mod> Power(const TModular<Mod>& a, int degree) {
    if (degree < 0) throw std::runtime_error("Wrong argument for power");
    TModular<Mod> x = a;
    TModular<Mod> res = 1;
    while (degree > 0) {
        if (degree & 1) res *= x;
        x *= x;
        degree >>= 1;
    }
    return res;
}

template <int Mod>
std::string to_string(const TModular<Mod>& number) {
    return to_string(number.value);
}

template <typename T>
T Inverse(T a, T m) {
    T u = 0, v = 1;
    T mod = m;
    while (a != 0) {
        T t = m / a;
        m -= t * a;
        std::swap(a, m);
        u -= t * v;
        std::swap(u, v);
    }
    if (m != 1) {
        throw std::runtime_error("Inverse does not exist: gcd(a, mod) != 1");
    }
    return u;
}

template <int Mod>
std::ostream& operator<<(std::ostream& out, const TModular<Mod>& number) {
    out << number.value;
    return out;
}

} // namespace NModular

// other primes: 1'000'000'007, 1'000'000'009
using Modular = NModular::TModular<998244353>;

} // anonimys namespace

class THash final {
public:
    explicit THash(const std::string& other);

    static Modular CountHash(const std::string& other);

    Modular GetHash(size_t l, size_t r) const;

    size_t Size() const;

#if not defined (DEBUG)
private:
#endif // DEBUG
    void ComputeForwardHash();
    static void EnsureCapacity(size_t n);

    template <typename T>
    friend T& operator<<(T& stream, const THash& hash);

#if not defined (DEBUG)
private:
#endif // DEBUG
    std::string Data_;
    std::vector<Modular> ForwardHash_;

    static int SmallNumber_;
    static int Modul_;
    static std::vector<Modular> Codes_;
    static std::vector<Modular> Power_;
};

#if defined (DEBUG)
template <typename T>
T& operator<<(T& stream, const THash& hash) {
    stream << "Modul_: " << hash.Modul_ << "\n";

    stream << "Codes_: ";
    for (const auto& i : hash.Codes_) {
        stream << i << " ";
    }
    stream << "\n";

    stream << "Power_: ";
    for (const auto& i : hash.Power_) {
        stream << i << " ";
    }
    stream << "\n";

    stream << "InversedPower_: ";
    for (const auto& i : hash.InversedPower_) {
        stream << i << " ";
    }
    stream << "\n";

    stream << "Data_: " << hash.Data_ << "\n";

    stream << "ForwardHash_: ";
    for (const auto& i : hash.ForwardHash_) {
        stream << i << " ";
    }
    stream << "\n";

    stream << "ReversedHash_: ";
    for (const auto& i : hash.ReversedHash_) {
        stream << i << " ";
    }
    stream << "\n";

    return stream;
}
#else
template <typename T>
T& operator<<(T& stream, const THash& hash) {
    stream << hash.ForwardHash_.back();
    return stream;
}
#endif // DEBUG

} // namespace NHash

namespace NHash {

constexpr int ABC = 26;
constexpr int SmallStringOptimizationMaximum = 16;

namespace {

int GenerateIntNumber(int from, int to) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(from, to);
    return dis(gen);
}

std::vector<Modular> GenerateCodes(int ABC) {
    std::vector<Modular> values;
    values.reserve(ABC);
    #if defined(DEBUG)
    for (int i = 1; i <= ABC; ++i) {
        values.push_back(i);
    }
    return values;
    #endif // DEBUG
    std::unordered_set<int> uniqueValues;

    while (values.size() < ABC) {
        int candidate = GenerateIntNumber(1000, 10000);
        if (uniqueValues.insert(candidate).second) {
            values.push_back(candidate);
        }
    }
    return values;
}

std::vector<Modular> GeneratePowers(int amount, Modular base) {
    std::vector<Modular> result;
    result.reserve(amount);
    result.emplace_back(1);

    for (int i = 1; i < amount; ++i) {
        result.emplace_back(result.back() * base);
    }
    return result;
}

} // anonymous namespace

#if defined(DEBUG)
int THash::SmallNumber_ = 11; // should be prime
#else
int THash::SmallNumber_ = 9901;
#endif // DEBUG
int THash::Modul_ = Modular::GetModule();
std::vector<Modular> THash::Codes_ = GenerateCodes(ABC);
std::vector<Modular> THash::Power_ = GeneratePowers(SmallStringOptimizationMaximum, SmallNumber_);

Modular THash::CountHash(const std::string& other) {
    EnsureCapacity(other.size());

    #if defined (DEBUG)
    for (const auto& i : other) {
        assert('a' <= i && i <= 'z');
    }
    #endif // DEBUG

    Modular result = 0;
    size_t n = other.size();
    if (n == 0) return 0;

    for (size_t i = 0; i < n; ++i) {
        result += Codes_[other[i] - 'a'] * Power_[n - i - 1];
    }
    return result;
}

THash::THash(const std::string& other) : Data_(other) {
    EnsureCapacity(other.size());
    ComputeForwardHash();
}

void THash::EnsureCapacity(size_t n) {
    if (Power_.size() < n) {
        size_t oldSize = Power_.size();
        Power_.reserve(n);

        Modular base = SmallNumber_;

        for (size_t i = oldSize; i < n; ++i) {
            Power_.emplace_back(Power_.back() * base);
        }
    }
}

void THash::ComputeForwardHash() {
    ForwardHash_.resize(Data_.size());
    if (Data_.empty()) return;

    ForwardHash_[0] = Codes_[Data_[0] - 'a'];
    for (size_t i = 1; i < Data_.size(); ++i) {
        ForwardHash_[i] = ForwardHash_[i - 1] * SmallNumber_ + Codes_[Data_[i] - 'a'];
    }
}

Modular THash::GetHash(size_t l, size_t r) const {
    if (!(l < r)) {
        #if defined (DEBUG)
        std::cout << "!(l < r)\n";
        #endif // DEBUG
        return 0;
    }
    if (!(0 <= l && l <= Size())) {
        #if defined (DEBUG)
        std::cout << "!(0 <= l && l <= Size())";
        #endif // DEBUG
        return 0;
    }
    if (!(0 <= r && r <= Size())) {
        #if defined (DEBUG)
        std::cout << "!(0 <= r && r <= Size())";
        #endif // DEBUG
        return 0;
    }
    if (l == 0) {
        return ForwardHash_[r - 1];
    }
    return ForwardHash_[r - 1] - ForwardHash_[l - 1] * Power_[r - 1 - (l - 1)];
}

size_t THash::Size() const {
    return Data_.size();
}

} // namespace NHash

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    #if not defined (LOCAL)
    freopen("search.in", "r", stdin);
    freopen("search.out", "w", stdout);
    #endif // LOCAL
    std::string s;
    std::cin >> s;
    size_t n = s.size();
    NHash::THash hash(s);
    std::string t;
    std::cin >> t;
    size_t m = t.size();
    auto targetHash = NHash::THash::CountHash(t);
    std::vector<int> result;
    for (size_t i = 0; i < n - m + 1; ++i) {
        if (targetHash == hash.GetHash(i, i + m)) {
            result.push_back(i);
        }
    }
    std::cout << result.size() << "\n";
    for (const auto& i : result) {
        std::cout << i + 1 << " ";
    }
    return 0;
}

/**



**/
