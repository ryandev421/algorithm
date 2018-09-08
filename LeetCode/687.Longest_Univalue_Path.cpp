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
    int getMaxPath(TreeNode* root, int& res)
    {
        int l = (root->left != NULL) ? getMaxPath(root->left, res) : 0;
        int r = (root->right != NULL) ? getMaxPath(root->right, res) : 0;
        int l_max = (root->left != NULL && root->left->val == root->val) ? l + 1 : 0;
        int r_max = (root->right != NULL && root->right->val == root->val) ? r + 1 : 0;
        res = max(res, l_max + r_max);
        return max(l_max, r_max);
    }
    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        if (root != NULL) getMaxPath(root, res);
        return res;
    }
};
