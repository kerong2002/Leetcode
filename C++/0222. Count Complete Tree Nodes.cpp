/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int ans;
public:
    void dfs(TreeNode* node) {
        if (!node) {
            return;
        }
        else {
            dfs(node->left);
            ans += 1;
            dfs(node->right);
        }
    }
    int countNodes(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};