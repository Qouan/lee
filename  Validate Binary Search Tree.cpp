//98
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {private:int last=INT_MIN;
public:
   bool search(TreeNode*root,TreeNode*&pre)
   {
        if(root)
	 {
			  if(!search(root->left,pre))return 0;           
              if(pre&&root->val<=pre->val)return 0;
               pre=root;
              if(!search(root->right,pre))return 0; 
	 }
	 return 1;
   }
  bool isValidBST(TreeNode* root) 
{
	TreeNode*pre=NULL;
      return search(root,pre);
  }
};
