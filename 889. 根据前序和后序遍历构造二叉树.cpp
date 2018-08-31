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
    bool cmp(set<int>&s1,set<int>&s2)
{
    set<int>::iterator it;
    set<int>::iterator it1;
//遍历集合中的所有元素 
    bool flag = true;
    for (it = s1.begin(), it1 = s2.begin(); it != s1.end(); it++, it1++){
        if (*it1 != *it){
            flag = false;
            break;
        }
    }
    return flag;
}
TreeNode* construct(vector<int>& pre, vector<int>& post,int s1,int s2,int e1,int e2)
{
    //cout<<s1<<s2<<e1<<e2<<endl;
    if(s1>e1)
        return NULL;
    if(s1==e1)
        return new TreeNode(pre[s1]);
    set<int>myset1,myset2;
    int index=-1;
    for(int i=s1+1,j=s2;i<=e1;++i,++j)
    {
        myset1.insert(pre[i]);
        myset2.insert(post[j]);
        //cout<<pre[i]<<post[j]<<endl;
        if(cmp(myset1,myset2))
        {
            index=j-s2;
            break;
        }
    }//cout<<index;
    TreeNode*l=construct(pre,post,s1+1,s2,s1+1+index,s2+index);
    TreeNode*r=construct(pre,post,s1+1+index+1,s2+index+1,e1,e2-1);
    TreeNode*root=new TreeNode(pre[s1]);
    root->left=l;root->right=r;
    return root;

}
TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post)
{
    return construct(pre,post,0,0,pre.size()-1,pre.size()-1);
}
};