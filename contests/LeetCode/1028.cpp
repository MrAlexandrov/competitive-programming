#include <iostream>
#include <stack>
#include <string>
#include <cassert>
#include <vector>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    struct DepthValue {
        int Depth;
        int Value;
    };
    DepthValue GetDepthValue(const std::string& traversal, size_t& position) const {
        DepthValue result{0, 0};
        size_t n = traversal.size();
        while (traversal[position] == '-') {
            ++result.Depth;
            ++position;
        }
        std::string number;
        while (position < n && traversal[position] != '-') {
            number += traversal[position];
            ++position;
        }
        result.Value = std::stoi(number);
        return result;
    }
    TreeNode* recoverFromPreorder(std::string traversal) {
        std::vector<DepthValue> parsed;
        size_t position = 0;
        size_t n = traversal.size();
        for (size_t i = 0; i < n;) {
            parsed.emplace_back(GetDepthValue(traversal, i));
        }
        std::stack<TreeNode*> stack;
        for (const auto[depth, value] : parsed) {
            TreeNode* newNode = new TreeNode(value);
            while (stack.size() > depth) {
                stack.pop();
            }
            if (!stack.empty()) {
                auto top = stack.top();
                if (top->left == nullptr) {
                    top->left = newNode;
                } else {
                    top->right = newNode;
                }
            }
            stack.push(newNode);
        }
        TreeNode* root = nullptr;
        while (!stack.empty()) {
            root = stack.top();
            stack.pop();
        }
        return root;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    return 0;
}

/**



**/
