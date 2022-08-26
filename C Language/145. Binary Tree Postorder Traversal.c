/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void postorder(struct TreeNode *root,int *list,int *index){
    if(root!=NULL){
        postorder(root->left,list,index);
        postorder(root->right,list,index);
        list[(*index)++]=root->val;
    }
}
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int *list=(int *)calloc(101,sizeof(int));
    *returnSize=0;
    postorder(root,list,returnSize);
    return list;
}