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
    vector<int>tmp;
void findallpath(TreeNode*root, vector<vector<int> >&path)
{
    if(root==NULL)
    {
        if(path.empty())path.push_back(tmp);
        else
        {
            if(path[0].size()==tmp.size())path.push_back(tmp);
            if(path[0].size()<tmp.size())
            {
                path.clear();
                path.push_back(tmp);
            }
        }
        return;
    }
    tmp.push_back(root->val);
    findallpath(root->left,path);
    findallpath(root->right,path);
    tmp.pop_back();
}
int find_branch(vector<vector<int> >&path)
{
    for(int i=0;i<path[0].size();++i)
    {
        int key=path[0][i];
        for(int j=1;j<path.size();++j)
        {
            if(path[j][i]!=key)
            return path[0][i-1];
        }
    }
    return path[0].back();
}
TreeNode*previsit(TreeNode*root,int target)
{
    if(root!= nullptr)
    {
        if(root->val==target){;return root;}
        TreeNode*res;
        if((res=previsit(root->left,target))!= nullptr)return res;
        if((res=previsit(root->right,target))!= nullptr)return res;
    }
    return nullptr;
}
TreeNode* subtreeWithAllDeepest(TreeNode* root)
{
    if(root==nullptr)
        return nullptr;
    vector<vector<int> >path;
    findallpath(root,path);
    int target=find_branch(path);
    return previsit(root,target);

}
};
