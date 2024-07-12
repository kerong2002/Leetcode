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
public:
    void dfs(TreeNode* root, int& ans, string cnt) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            cnt.push_back(root->val + '0');
            ans += stoi(cnt);
        }
        cnt.push_back(root->val + '0');
        dfs(root->left, ans, cnt);
        dfs(root->right, ans, cnt);
    }

    int sumNumbers(TreeNode* root) {
        int ans = 0;
        string cnt;
        dfs(root, ans, cnt);
        return ans;    
    }
};