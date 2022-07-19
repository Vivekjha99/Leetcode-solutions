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
    int solve(TreeNode* root,int &val,int &ans){
        if(root->left!=NULL)solve(root->left,val,ans);
        if(val>=0)
            ans=min(ans,root->val-val);
        val=root->val;
        if(root->right!=NULL)
        solve(root->right,val,ans);
        return ans;
    }
    int getMinimumDifference(TreeNode* root) {
        int val=-1,ans=INT_MAX;
        return solve(root,val,ans);
    }
};