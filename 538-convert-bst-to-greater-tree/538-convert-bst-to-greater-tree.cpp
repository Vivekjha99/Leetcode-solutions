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
    private:
        int sum=0;
    public:
    void solve(TreeNode*  root){
        if(root==NULL)return;
        if(root->right)solve(root->right);
        root->val=(sum+=root->val);
        if(root->left)solve(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        solve(root);
        return root;
    }
};