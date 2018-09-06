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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1)
    {
        TreeNode* head=new TreeNode(v);
        head->left=root;
        return head;
    }
    queue<TreeNode*>q;
    q.push(root);
    int level=2;
    while(!q.empty())
    {
        if(level==d)
        {
            while(!q.empty())
            {
                TreeNode*fro=q.front();
                q.pop();
                TreeNode*l=new TreeNode(v);
                l->left=fro->left;
                fro->left=l;

                TreeNode*r=new TreeNode(v);
                r->right=fro->right;
                fro->right=r;
            }
            return root;
        }
        int len=q.size();
        for(int i=0;i<len;++i)
        {
            TreeNode*fro=q.front();
            q.pop();
            if(fro->left!= nullptr)q.push(fro->left);
            if(fro->right!= nullptr)q.push(fro->right);
        }
        ++level;
    }
    return root;
    }
};