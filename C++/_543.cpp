
typedef struct TreeNode
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
    int diameterOfBinaryTree(TreeNode *root)
    {
        int d = 0;
        diameter(root, d);
        return d;
    }

    int diameter(TreeNode *root, int &maxDiameter)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int l = diameter(root->left, maxDiameter) + 1;
        int r = diameter(root->right, maxDiameter) + 1;

        int d = l + r - 2;
        if (maxDiameter < d)
        {
            maxDiameter = d;
        }

        return l > r ? l : r;
    }
};