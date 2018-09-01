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
    int robber(TreeNode*root,int flag)
{
    if(root== nullptr)return 0;
    if(flag==1)
    {
        return max(robber(root->left,1)+robber(root->right,1),
        root->val+robber(root->left,0)+robber(root->right,0));
    }
    else
    {
        return robber(root->left,1)+robber(root->right,1);
    }
}
int rob(TreeNode*root)
{
    return robber(root,1);
}

};
