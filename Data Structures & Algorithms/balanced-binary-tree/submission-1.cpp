/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
int maxheight(TreeNode*root){
    if(root==nullptr) return 0;
    return 1 + max(maxheight(root->left),maxheight(root->right));
}
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;
        int left=maxheight(root->left);
        int right=maxheight(root->right);
        if(abs(left - right) <= 1) return isBalanced(root->left) && isBalanced(root->right);
        else return false;
    }
};