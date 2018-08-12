/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL)return ;
	   queue<TreeLinkNode*>nodes;
	   queue<TreeLinkNode*>next_level;
	   nodes.push(root);
	   while(!nodes.empty())
	   {
			  TreeLinkNode*p=nodes.front();
			  nodes.pop();
			   if(p->left!=NULL)next_level.push(p->left);
			  if(p->right!=NULL)next_level.push(p->right);
			  while(!nodes.empty())
			  {
					  TreeLinkNode*q=nodes.front();
					  nodes.pop();
					 if(q->left!=NULL) next_level.push(q->left);
					 if(q->right!=NULL) next_level.push(q->right);
					  p->next=q;
					  p=q;
			 }
			 nodes=next_level;
           while(!next_level.empty())next_level.pop();
	   }
    }
};
