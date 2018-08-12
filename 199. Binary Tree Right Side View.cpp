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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        visit(root,res,0);
        return res;
    }
    void visit(TreeNode* root,vector<int>&res,int level)
    {
        if(root==NULL)return ;
        if(res.size()==level)
        res.push_back(root->val);
        visit(root->right,res,level+1);
        visit(root->left,res,level+1);
    }
};
