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
    vector<TreeNode*> bfs(int start, int end) {
        vector<TreeNode*> ans;
        if (start > end) {
            ans.push_back(nullptr);
            return ans;
        }
        else {
            for (int y = start; y <= end; ++y) {
                vector<TreeNode*> L = bfs(start, y - 1);
                vector<TreeNode*> R = bfs(y + 1, end);
                for (auto l : L) {
                    for (auto r : R) {
                        TreeNode* temp = new TreeNode(y, l, r);
                        ans.push_back(temp);
                    }
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return vector<TreeNode*> (0);
        }
        return bfs(1, n);
    }
};