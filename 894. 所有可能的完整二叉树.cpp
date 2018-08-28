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
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N%2==0)return {};
    if(N==1)
        return {new TreeNode(0)};
    vector<TreeNode*>res;
    for(int i=1;i<N;i+=2)
    {
        vector<TreeNode*>l=allPossibleFBT(i);
        vector<TreeNode*>r=allPossibleFBT(N-i-1);
        for(int j=0;j<l.size();++j)
            for(int k=0;k<r.size();++k)
            {
                auto root=new TreeNode(0);
                root->left=l[j];
                root->right=r[k];
                res.push_back(root);
            }
    }
    return res;
    }
};