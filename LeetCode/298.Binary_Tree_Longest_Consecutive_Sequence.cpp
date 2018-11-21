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
    int longestConsecutive(TreeNode* root) {
        if (root == NULL) return 0;
        else return longestConsecutive(root, 1);
    }
    
    int longestConsecutive(TreeNode* root, int par_length) {
        int max_val = par_length;
        if (root->left != NULL) {
            max_val = max(max_val, longestConsecutive(root->left, (root->val+1 == root->left->val) ? par_length + 1 : 1));
        }
        if (root->right != NULL) {
            max_val = max(max_val, longestConsecutive(root->right, (root->val+1 == root->right->val) ? par_length + 1 : 1));
        }
        return max_val;
    }
};