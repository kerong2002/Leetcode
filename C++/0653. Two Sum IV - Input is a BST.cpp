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
    bool search(TreeNode *root,int k,unordered_set<int>& list){
        if(!root){
            return false;
        }
        if(list.count(k-root->val)){
            return true;//尋找是否有另一個數字
        }
        list.insert(root->val);//放入Set
        return search(root->left,k,list) || search(root->right,k,list);;
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> list;
        return search(root,k,list);
    }
};