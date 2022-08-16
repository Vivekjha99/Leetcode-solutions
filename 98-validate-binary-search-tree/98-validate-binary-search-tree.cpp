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
    bool solve(TreeNode* root,TreeNode* &pre){
        if(root==NULL)return true;
        //inorder traversal
        if(!solve(root->left,pre))return false;
        if(pre!=NULL && pre->val>=root->val)return false;
        pre=root;
        return solve(root->right,pre);
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* pre=NULL;
        return solve(root,pre);
    }
};