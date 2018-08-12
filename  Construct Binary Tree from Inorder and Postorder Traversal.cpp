//106
class Solution {
public:
    TreeNode* creator(vector<int>& preorder, vector<int> inorder,int pre_left,int pre_start,int in_star,int in_end)
{
	   if(in_star==in_end)return new TreeNode(inorder[in_star]);
        if(in_star>in_end)return NULL;
	   int i;
	   for(i=in_star;i<=in_end;++i)
	   if(inorder[i]==preorder[pre_start])break;
	   TreeNode *root = new TreeNode(preorder[pre_start]);
	   root->left=creator(preorder,inorder,pre_left,pre_left+i-in_star-1,in_star,i-1);
	   root->right=creator(preorder,inorder,pre_left+i-in_star,pre_start-1,i+1,in_end);
	   return root;
}

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty())return NULL;
            return creator(postorder,inorder,0,postorder.size()-1,0,inorder.size()-1);
    }
};
