
typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return 1;

        int r =0, l = 0 , d = 0;
        if(root->right != nullptr) r = maxDepth(root->right)+1; 
        if(root->left != nullptr) l = maxDepth(root->left)+1;
        d = r > l ? r : l;
        return d; 
    }
};