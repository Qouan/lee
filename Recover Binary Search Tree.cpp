/*99. Recover Binary Search Tree
DescriptionHintsSubmissionsDiscussSolution
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
Follow up:

A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution?
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {private:vector<int>res;int i=0;
public:
   void preorder(TreeNode*root)
 {
	   if(root)
	   {
			  preorder(root->left);
			  res.push_back(root->val);
			  preorder(root->right);
	   }
 }

void recover(TreeNode *root)
{
	    if(root)
	   {
			  recover(root->left);
			  root->val=res[i];
			  i++;
			  recover(root->right);
	   }
}
 void recoverTree(TreeNode* root)
 {
	   preorder(root);
	   sort(res.begin(),res.end());
     for(int i=0;i<res.size();++i)cout<<res[i];
     recover(root);
 }
};
