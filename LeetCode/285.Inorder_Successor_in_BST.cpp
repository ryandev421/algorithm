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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *cur_node = root;
        TreeNode *parent_of_left_child = NULL;
        while (cur_node != NULL)
        {
            if (cur_node->val <= p->val) {
                cur_node = cur_node->right;
            } else {
                parent_of_left_child = cur_node;
                cur_node = cur_node->left;
            }
        }
        return parent_of_left_child;
    }
};
