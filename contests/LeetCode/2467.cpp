#include <functional>
#include <iostream>
#include <limits>
#include <vector>

// class Solution {
// public:
//     int mostProfitablePath(std::vector<std::vector<int>>& edges, int bob, std::vector<int>& amount) {
//         int nodes = static_cast<int>(amount.size());
//         std::vector<std::vector<int>> graph(nodes);
//         std::vector<int> parent(nodes);
//         for (const auto& edge : edges) {
//             int u = edge.front();
//             int v = edge.back();
//             graph[u].push_back(v);
//             graph[v].push_back(u);
//         }
//         std::vector<int> localAnswer(amount);

//         int answer = std::numeric_limits<int>::min();
//         std::function<void(int, int)> DFS = [&](int currentNode, int previous) {
//             parent[currentNode] = previous;
//             for (const auto& nextNode : graph[currentNode]) {
//                 if (nextNode == previous) continue;
//                 localAnswer[nextNode] += localAnswer[currentNode];
//                 DFS(nextNode, currentNode);
//             }
//             if (currentNode != 0 && graph[currentNode].size() == 1) {
//                 answer = std::max(answer, localAnswer[currentNode]);
//             }
//         };
//         DFS(0, 0);
//         return answer;
//     }
// };

class Solution {
public:
    int mostProfitablePath(std::vector<std::vector<int>>& edges, int bob, std::vector<int>& amount) {
        int numberNodes = static_cast<int>(edges.size()) + 1;
        std::vector<std::vector<int>> graph(numberNodes);
        for (const auto& edge : edges) {
            int from = edge[0];
            int to = edge[1];
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        std::vector<int> timestamps(numberNodes, numberNodes);
        std::function<bool(int, int, int)> dfsUpdateTimeStamps = [&](int vertex, int parent, int time) -> bool {
            if (vertex == 0) {
                timestamps[vertex] = time;
                return true;
            }
            for (int neighbor : graph[vertex]) {
                if (neighbor != parent && dfsUpdateTimeStamps(neighbor, vertex, time + 1)) {
                    timestamps[neighbor] = std::min(timestamps[neighbor], time + 1);
                    return true;
                }
            }
            return false;
        };
        dfsUpdateTimeStamps(bob, -1, 0);
        timestamps[bob] = 0;
        int maximumProfit = std::numeric_limits<int>::min();
        std::function<void(int, int, int, int)> dfsCalculateProfit = [&](int vertex, int parent, int time, int profit) {
            if (time == timestamps[vertex]) {
                profit += amount[vertex] / 2;
            }
            else if (time < timestamps[vertex]) {
                profit += amount[vertex];
            }
            if (static_cast<int>(graph[vertex].size()) == 1 && graph[vertex][0] == parent) {
                maximumProfit = std::max(maximumProfit, profit);
                return;
            }
            for (int neighbor : graph[vertex]) {
                if (neighbor != parent) {
                    dfsCalculateProfit(neighbor, vertex, time + 1, profit);
                }
            }
        };
        dfsCalculateProfit(0, -1, 0, 0);
        return maximumProfit;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n = 0;
    std::cin >> n;
    std::vector<std::vector<int>> edges;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        edges.push_back({u, v});
    }
    int bob = 0;
    std::cin >> bob;
    std::vector<int> amount(n);
    for (auto& i : amount) {
        std::cin >> i;
    }
    Solution solve;
    std::cout << solve.mostProfitablePath(edges, bob, amount);
    return 0;
}

/**



**/
