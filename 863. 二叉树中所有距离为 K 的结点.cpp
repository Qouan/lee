class Solution {vector<TreeNode*>path;
public:
    bool findpath(TreeNode*root,TreeNode*target,vector<TreeNode*>&path)
    {

        if(root==target)
        {
            path.push_back(target);
            return true;
        }
        if(root) {//cout<<root->val;
            path.push_back(root);
            if(findpath(root->left, target, path)||
               findpath(root->right, target, path))
                return true;
            path.pop_back();
        }
        return false;
    }
    void findK(TreeNode*root,TreeNode*target,vector<int>&res,int i)
    {
        if(!root)return;
        if(i==0&&find(res.begin(),res.end(),root->val)==res.end())res.push_back(root->val);
        --i;
        findK(root->left,target,res,i);
        findK(root->right,target,res,i);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K)
    {

        findpath(root,target,path);
        cout<<path.size();
        vector<int>res;
        int p=static_cast<int>(path.size()-K);
        if(p-1>=0)res.push_back(path[p-1]->val);
        for(int i=max(p,0);i<path.size()-1;++i) {
            //cout<<i;
            if(find(path.begin(),path.end(),path[i]->left)!=path.end())
            {
               // cout<<K-1-(path.size()-1-i);
                findK(path[i]->right,target,res,K-1-(path.size()-1-i));
            }
            else
                findK(path[i]->left,target,res,K-1-(path.size()-1-i));
        }
        findK(path.back(),target,res,K);
        return res;
    }
};