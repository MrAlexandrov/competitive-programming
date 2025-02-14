#include <functional>
#include <iostream>
#include <memory>
#include <ostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>

struct TNode {
    bool Terminate = false;
    std::unordered_map<std::string, std::shared_ptr<TNode>> Next;

    std::shared_ptr<TNode> operator[](const std::string& index) {
        auto exists = Next.find(index);
        if (exists == Next.end()) {
            Next[index] = std::make_shared<TNode>();
        }
        return Next[index];
    }

    size_t size() const {
        return Next.size();
    }
};

class Solution {
public:
    std::vector<std::string> removeSubfolders(std::vector<std::string>& folder) {
        const std::shared_ptr<TNode> Root = std::make_shared<TNode>();
        for (const auto& str : folder) {
            auto currentStart = Root;
            std::stringstream ss(str);
            char delimiter = '/';
            std::string token;
            while (std::getline(ss, token, delimiter)) {
                if (token.empty()) continue;
                currentStart = currentStart->operator[](token);
            }
            currentStart->Terminate = true;
        }
        std::vector<std::string> currentPath;
        auto addCurrentPath = [&]() {
            std::string result;
            for (const auto& file : currentPath) {
                result += "/" + file;
            }
            return result;
        };
        std::vector<std::string> answer;
        std::function<void(std::shared_ptr<TNode>)> DFS = [&](std::shared_ptr<TNode> currentFolder){
            for (const auto& file : currentFolder->Next) {
                if (file.second->Terminate) {
                    currentPath.push_back(file.first);
                    answer.emplace_back(addCurrentPath());
                    currentPath.pop_back();
                    continue;
                } else {
                    currentPath.push_back(file.first);
                    DFS(file.second);
                    currentPath.pop_back();
                }
            }
        };
        DFS(Root);
        return answer;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::string> folders;
    folders.reserve(n);
    for (int i = 0, end = n; i < end; ++i) {
        std::string x;
        std::cin >> x;
        folders.emplace_back(std::move(x));
    }
    Solution solve;
    std::vector<std::string> result = solve.removeSubfolders(folders);
    for (const auto& i : result) {
        std::cout << i << "\n";
    }
    return 0;
}

/**



**/
