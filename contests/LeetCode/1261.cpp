#include <functional>
#include <iostream>
#include <cassert>
#include <unordered_set>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
        {
        }
};

class FindElements {
public:
    FindElements(TreeNode* root) {
        root->val = 0;

        std::function<void(TreeNode*)> recoverTree = [&](TreeNode* node) {
            Values_.insert(node->val);

            if (node->left) {
                node->left->val = (node->val) * 2 + 1;
                recoverTree(node->left);
            }

            if (node->right) {
                node->right->val = (node->val) * 2 + 2;
                recoverTree(node->right);
            }
        };

        recoverTree(root);
    }

    bool find(int target) {
        return Values_.contains(target);
    }
private:
    std::unordered_set<int> Values_;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    return 0;
}

/**



**/
