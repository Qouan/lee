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
    bool remove(TreeNode*root) {
    if(root== nullptr)
        return false;
    bool l = remove(root->left);
    bool r = remove(root->right);
    if (!l)root->left = nullptr;
    if (!r)root->right = nullptr;
    return l || r || root->val == 1;
}
TreeNode* pruneTree(TreeNode* root)
{
    if(!remove(root))return NULL;
    return root;
}
};