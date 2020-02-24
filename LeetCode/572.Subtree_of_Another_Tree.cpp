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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL && t != NULL) {
            return false;
        }
        return isEquals(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    
    bool isEquals(const TreeNode *s, const TreeNode *t) {
        if (s == NULL && t == NULL) {
            return true;
        }
        if (s == NULL || t == NULL) {
            return false;
        }
        return s->val == t->val && isEquals(s->left, t->left) && isEquals(s->right, t->right);
    }
};