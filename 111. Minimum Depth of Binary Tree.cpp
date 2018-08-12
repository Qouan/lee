class Solution {
public:
     int high(TreeNode*&root)
 {
	   if(NULL==root)return 0;
	   int l=high(root->left);
         //cout<<"l"<<l;
	   int r=high(root->right);
         //cout<<"r"<<r;
	   if(l==0)return r+1;//注意子树为0的情况
    if(r==0)return l+1;
         return min(l,r)+1;
        
 }

int minDepth(TreeNode* root)
{
	   return high(root);
}
};
