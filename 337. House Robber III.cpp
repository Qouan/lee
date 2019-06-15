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
    vector<int> helper(TreeNode*root){
    if(root==NULL)
        return {0,0};
    vector<int>left=helper(root->left);
    vector<int>right=helper(root->right);
    int l1=left[0],l2=left[1];
    int r1=right[0],r2=right[1];
    return {root->val+l2+r2,max(l1,l2)+max(r1,r2)};
}

int rob(TreeNode* root){
    vector<int>res=helper(root);
    return *max_element(res.begin(),res.end());
}
};