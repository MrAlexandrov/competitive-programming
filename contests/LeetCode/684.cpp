#include <cassert>
#include <functional>
#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator << (std::ostream& out, std::vector<T> item) {
    for (auto&& i : item) {
        out << i << " ";
    }
    return out;
}

std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges) {
    int n = static_cast<int>(edges.size());
    for (auto&& i : edges) {
        for (auto&& j : i) {
            --j;
        }
    }

    std::vector<int> parent(n);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    std::vector<int> size(n, 1);

    std::function<int(int)> leader = [&leader, &parent](int v) -> int {
        return (parent[v] == v ? v : parent[v] = leader(parent[v]));
    };

    auto same = [&leader](int a, int b) -> bool {
        return (leader(a) == leader(b));
    };

    auto unite = [&leader, &same, &parent, &size](int a, int b) -> void {
        a = leader(a);
        b = leader(b);
        if (size[a] > size[b]) {
            std::swap(a, b);
        }
        size[b] += size[a];
        parent[a] = b;
    };

    std::vector<int> result = edges[0];

    for (auto&& edge : edges) {
        assert(static_cast<int>(edge.size()) == 2);
        int u = edge[0];
        int v = edge[1];
        if (same(u, v)) {
            result = {u + 1, v + 1};
        } else {
            unite(u, v);
        }
    }

    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> edges;
    edges.resize(n);
    for (auto&& i : edges) {
        std::vector<int> current(2);
        std::cin >> current[0] >> current[1];
        i = current;
    }
    std::cout << findRedundantConnection(edges);
    return 0;
}

/**



**/