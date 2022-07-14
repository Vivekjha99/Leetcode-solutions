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
    unordered_map<int,int>mp;
    TreeNode* solve(vector<int>&in,vector<int>&po,int s,int e,int &pidx){
        if(s>e)return NULL;
        int idx=mp[po[pidx]];
        pidx--;
        TreeNode* root=new TreeNode(in[idx]);
        root->right=solve(in,po,idx+1,e,pidx);
        root->left=solve(in,po,s,idx-1,pidx);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        int pidx=n-1;
        return solve(inorder,postorder,0,n-1,pidx);
    }
};