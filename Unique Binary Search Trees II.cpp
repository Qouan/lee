//95
/*
这道题是 Unique Binary Search Trees 的升级版，解决方法同样是动态规划。

在做 Unique Binary Search Trees 这道题时，我们用一个数组保存 1 至 n-1 对应的不同二叉树的个数 X1、X2、X3、... Xn-1，

则 n 对应的不同二叉树个数Xn = Xn-1 + X1*Xn-2 + X2*Xn-3 + X3*Xn-4 + ... + Xn-2*X1 + Xn-1

 　　通过这个递推式，我们可以从 N = 1 开始递推，最后得到 N = n 时不同二叉查找树的个数。

 

与上述思路类似，我们可以通过深度优先搜索（递归）解决这道题。

因为二叉查找树满足父节点的值大于左子节点的值，小于右子节点的值，所以我们可以：

(1) 从 N=1 开始构建二叉查找树，则它的左子树节点数为 0，右子树节点数为 n-1；

(2) N=2 时，左子树节点数为 1，右子树节点数为 n-2；

……

(n) N=n 时，左子树节点数为 n-1，右子树节点数 0。

 

而在第(1)步中，右子树继续执行上述循环，子树的子树又执行这个循环，最终，我们可以将子树节点数减少到 1，而一个节点只有一种排列方式，所以此时可以毫不犹豫地将结果返回给上一级。然后包含有两个节点的二叉树排列方式又被返回给上一级。……

依此类推，我们最后可以得到所有不同结构的二叉查找树。
*/
#include<iostream>
#include<vector>
#include<string.h>
#include<map>
#include<algorithm>
using namespace std;

 struct TreeNode {
	  int val;
	  TreeNode *left;
	  TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
vector<TreeNode*> gene_strct(int start,int end)
{	    vector<TreeNode*>res;
	   if(start>end){res.push_back(NULL);return res;}
	   if(start==end){TreeNode* res_node=new TreeNode(start);  res.push_back(res_node);return res;}
	   for(int i=start;i<=end;++i)
	   {
			  vector<TreeNode*>le=gene_strct(start,i-1);
			  vector<TreeNode*>ri=gene_strct(i+1,end);
			  
			  for(int i=0;i<le.size();++i)
			  for(int j=0;j<ri.size();++j){TreeNode *root = new TreeNode(i);
			  root->left=le[i];
			  root->right=ri[j];
			  res.push_back(root);}
		}
		return res;
}

vector<TreeNode*> generateTrees(int n)
{
	  return  gene_strct(1,n);
}
int main()
{
	   vector<TreeNode*>res=generateTrees(3);
	   int a=0;
}





