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
    int closestValue(TreeNode* root, double target) {
        int min_num = -std::numeric_limits<int>::max();
        int max_num = std::numeric_limits<int>::max();
        
        while (root != NULL) {
            if (root->val > target) {
                max_num = min(max_num, root->val);
                root = root->left;
            } else {
                min_num = max(min_num, root->val);
                root = root->right;
            }
        }
        int res;
        if (min_num == -std::numeric_limits<int>::max()) {
            res = max_num;
        } else if(max_num == std::numeric_limits<int>::max()) {
            res = min_num;
        } else {
            res = (target-min_num < max_num - target) ? min_num : max_num;
        }
        return res;
    }
};
