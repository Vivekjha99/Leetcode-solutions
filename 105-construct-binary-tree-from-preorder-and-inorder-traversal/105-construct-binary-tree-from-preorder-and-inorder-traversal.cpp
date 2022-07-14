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
    TreeNode* build(vector<int>&preorder,vector<int>&inorder,int &ridx,int l, int r){
        if(l>r)return NULL;
        int pivot=l;
        while(inorder[pivot]!=preorder[ridx])pivot++;
        ridx++;
        TreeNode* root=new TreeNode(inorder[pivot]);
        root->left=build(preorder,inorder,ridx,l,pivot-1);
        root->right=build(preorder,inorder,ridx,pivot+1,r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ridx=0;
        return build(preorder,inorder,ridx,0,preorder.size()-1);
    }
    
};