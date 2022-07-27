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
    int helper(TreeNode* root,int d){
        depth=max(depth,d);
        if(root==NULL)return d;
        int l=helper(root->left,d+1);
        int r=helper(root->right,d+1);
        if(l==depth && r==depth)
            lca=root;
        return max(l,r);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        helper(root,0);
        return lca;
        
    }
};