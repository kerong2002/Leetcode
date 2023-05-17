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
    TreeNode* search(vector<int>& inorder, vector<int>& postorder, int inorderL, int inorderR, int postorderL, int postorderR) {
        if (inorderL > inorderR || postorderL > postorderR) {
            return nullptr;
        }
        else {
            int post_number = postorder[postorderR];
            int post_position = distance(inorder.begin(), find(inorder.begin(), inorder.end(), post_number));
            //printf("%d , %d , %d , %d\n", inorderL, inorderR, postorderL, postorderR);
            TreeNode* curr = new TreeNode(post_number);
            curr->left = search(inorder, postorder, inorderL, post_position - 1, postorderL, postorderL + post_position - inorderL - 1);
            curr->right = search(inorder, postorder, post_position + 1, inorderR, postorderL + post_position - inorderL, postorderR - 1);
            return curr;
        }
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return search(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};