//https://blog.csdn.net/this_is_qiqi/article/details/77859419
/*首先要考虑到二叉树中的节点存在正数也存在负数，且最大路径和所在路径是任意两个节点的通路或者是一个节点自己。

所以不能直接使用之前根节点到叶子节点的最大路径和的求解方法。

1.如果这个节点是空，则返回值为0；

2.遍历节点的左子树和右子树，将左子树的最大不分叉路径（大于0）+右子树的最大不分叉路径（大于0）+节点本身的值

与当前最大路径和Max作比较，将较大的数保存于Max；

3.返回左右节点的中较大不分叉路径和（大于零）+节点值，作为递归调用。*/
class Solution {
public:
    int findmax(TreeNode*&root,int& mx)
{
	   if(root==NULL)return 0;
	   int left=findmax(root->left,mx);
	   int right=findmax(root->right,mx);
	   mx=max(mx,max(left,0)+max(right,0)+root->val);
	     return max(max(left,right),0)+root->val;
}

int maxPathSum(TreeNode* root)
{
        if(root==NULL)return 0;
	   int mx=INT_MIN;
	   findmax(root,mx);
	   return mx;
}
};

