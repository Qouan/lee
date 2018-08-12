class Solution {
public:
    bool search(TreeNode* root,int sum,int target)
    {
        if(NULL==root)return 0;
        if(root->left==NULL&&root->right==NULL&&sum+root->val==target)return 1;//判断叶子节点
        {
            //sum+=root->val;
            if(search(root->left,sum+root->val,target))return 1;
            if(search(root->right,sum+root->val,target))return 1;
        }
        return 0;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)return 0;
        return search(root,0,sum);
    }
};
