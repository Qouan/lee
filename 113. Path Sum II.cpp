class Solution {private:vector<vector<int>>res;
public:
     void search(TreeNode* &root,int sum,int target,vector<int>&bucket)
    {
        if(NULL==root)return ;
        if(root->left==NULL&&root->right==NULL&&sum+root->val==target)//判断叶子节点
        {
            bucket.push_back(root->val);
            res.push_back(bucket);
            bucket.pop_back();
            return ;
        }
        {
            bucket.push_back(root->val);
            search(root->left,sum+root->val,target,bucket);
            search(root->right,sum+root->val,target,bucket);
            bucket.pop_back();
        }
        return ;
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
         if(!root)return {};
        vector<int>bucket;
         search(root,0,sum,bucket);
        return res;
    }
};
