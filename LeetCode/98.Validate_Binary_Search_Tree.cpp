/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTWithMinMax(root, std::numeric_limits<long long>::min(), std::numeric_limits<long long>::max());
    }
    
    bool isValidBSTWithMinMax(TreeNode* root, const long long min, const long long max)
    {
        if (root == NULL) return true;
        if (root->val <= min || root->val >= max) return false;
        
        return isValidBSTWithMinMax(root->left, min, root->val) && isValidBSTWithMinMax(root->right, root->val, max);
    }
};
