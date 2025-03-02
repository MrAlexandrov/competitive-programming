#include <sstream>
#include <string>
#include <vector>
#include <iostream>

template <typename T>
std::istream& operator>>(std::istream& in, std::vector<T>& value) {
    std::string s;
    std::getline(in >> std::ws, s);
    std::stringstream ss{s};
    value.clear();
    T x;
    while (ss >> x) {
        value.emplace_back(x);
    }
    return in;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& value) {
    for (const auto& i : value) {
        out << i << " ";
    }
    return out;
}
