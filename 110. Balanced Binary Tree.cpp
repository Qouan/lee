//110
class Solution {
public:
    int high(TreeNode*root)
  {
	   if(NULL==root)return 0;
	   int left=high(root->left);
	   int right=high(root->right);
	   return max(left,right)+1;
  }

 bool isBalanced(TreeNode* root)
 {
	   if(NULL==root)return true;
	   if(abs(high(root->left)-high(root->right))>1)return false;
	   if(!isBalanced(root->left)||!isBalanced(root->right))return false;
     return true;
 }
