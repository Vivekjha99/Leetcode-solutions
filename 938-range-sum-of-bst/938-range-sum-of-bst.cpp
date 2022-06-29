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
    int sum;
    void inorder(TreeNode* root,int l,int r){
        if(!root)return;
        inorder(root->left,l,r);
        if(root->val >=l && root->val <=r)sum+=root->val;
        inorder(root->right,l,r);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)return 0;
        sum=0;
        inorder(root,low,high);
        return sum;
    }
};