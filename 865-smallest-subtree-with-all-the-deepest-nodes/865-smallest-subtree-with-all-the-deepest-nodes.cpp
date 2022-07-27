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
    TreeNode* lca;
    int depth=0;
    int solve(TreeNode* root,int d){
        depth=max(depth,d);
        if(root==NULL)return d;
        int l=solve(root->left,d+1);
        int r=solve(root->right,d+1);
        if(l==depth && r==depth)lca=root;
        return max(l,r);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        solve(root,0);
        return lca;
    }
};