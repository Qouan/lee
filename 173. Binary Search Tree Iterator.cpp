/*如果不看注意的话，一个非常简单的解决办法是遍历这棵二叉树，把二叉树的元素以从大到小的方式放到一个栈里，这样next()从栈顶获取元素，hasNext()调用栈不为空的判定方法。这种方法能满足题目中的时间复杂度要求，但是O(n)的空间复杂度无法满足题目中O(h)空间复杂度要求。

我们维护一个栈，暂且称之为最小元素栈，栈中存放的是结点指针，向栈中添加元素发生在两种情况下：1.初始化迭代器时；2.调用next()从栈中弹出一个元素时。我们结合下面的实例来描述这个栈中元素的添加和删除过程。对于hasNext()方法，调用栈的empty()方法即可，不做具体分析，仅分析next()方法以及迭代器的数据结构。

*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {private:stack<TreeNode*>minis;
public:
    BSTIterator(TreeNode *root) {
        if(root!=NULL){
        do{minis.push(root);}
        while(root=root->left);
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !minis.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode*p=minis.top();
        minis.pop();
        if(p->right)
        {
            TreeNode*s=p->right;
            do{minis.push(s);}
            while(s=s->left);
        }
        return p->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
