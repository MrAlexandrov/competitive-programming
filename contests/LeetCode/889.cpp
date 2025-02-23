#include <iostream>
#include <memory>
#include <stack>
#include <vector>

struct TreeNode {
    int val;
    std::shared_ptr<TreeNode> left;
    std::shared_ptr<TreeNode> right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, std::shared_ptr<TreeNode> left, std::shared_ptr<TreeNode> right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    std::shared_ptr<TreeNode> constructFromPrePost(std::vector<int>& preorder, std::vector<int>& postorder) {
        size_t n = preorder.size();
        int i = 0;
        int j = 0;
        std::stack<std::shared_ptr<TreeNode>> recover;
        auto root = std::make_shared<TreeNode>(preorder[i++]);
        recover.push(root);
        for (; i < n; ++i) {
            auto node = std::make_shared<TreeNode>(preorder[i]);
            while (
                !recover.empty() && j < n
                && recover.top()->val == postorder[j]
            ) {
                recover.pop();
                ++j;
            }
            if (recover.top()->left == nullptr) {
                recover.top()->left = node;
            } else {
                recover.top()->right = node;
            }
            recover.push(node);
        }
        return root;
    }
};

std::vector<int> checkPreorder;
std::vector<int> checkPostorder;

template <typename T>
void print(T root) {
    checkPreorder.push_back(root->val);
    if (root->left != nullptr) {
        print(root->left);
    }
    if (root->right != nullptr) {
        print(root->right);
    }
    checkPostorder.push_back(root->val);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> preorder(n);
    for (auto& i : preorder) {
        std::cin >> i;
    }
    std::vector<int> postorder(n);
    for (auto& i : postorder) {
        std::cin >> i;
    }
    Solution solve;
    auto check = solve.constructFromPrePost(preorder, postorder);

    print(check);
    for (const auto& i : checkPreorder) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for (const auto& i : checkPostorder) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}

/**



**/
