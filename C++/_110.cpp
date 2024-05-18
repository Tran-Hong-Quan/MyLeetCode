#include <iostream>
#include <vector>
#include <algorithm>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int height(TreeNode *node)
    {
        if (node == nullptr)
            return 0;
        if (node->left == nullptr && node->right == nullptr)
            return 1;
        int l = height(node->left) + 1;
        int r = height(node->right) + 1;
        return l > r ? l : r;
    }

    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return true;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if (abs(leftHeight - rightHeight) > 1)
            return false;

        bool leftBanlanced = isBalanced(root->left);
        bool rightBanlanced = isBalanced(root->right);

        return rightBanlanced && leftBanlanced;
    }
};