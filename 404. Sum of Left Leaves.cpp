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
    bool isLeaves(TreeNode*root){
    if(root!=NULL&&root->left==NULL&&root->right==NULL)
        return true;
    return false;
}
int sumOfLeftLeaves(TreeNode* root) {
    if(root==NULL)return 0;
    if(isLeaves(root->left))return root->left->val+sumOfLeftLeaves(root->right);
    else return sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
}
};