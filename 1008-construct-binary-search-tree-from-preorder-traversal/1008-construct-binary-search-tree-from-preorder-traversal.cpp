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
    TreeNode* helper(vector<int>&nums,int &idx,int bound){
        if(idx==nums.size()|| nums[idx]>bound)return NULL;
        TreeNode* root=new TreeNode(nums[idx++]);
        root->left=helper(nums,idx,root->val);
        root->right=helper(nums,idx,bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
        return helper(preorder,idx,INT_MAX);
    }
};