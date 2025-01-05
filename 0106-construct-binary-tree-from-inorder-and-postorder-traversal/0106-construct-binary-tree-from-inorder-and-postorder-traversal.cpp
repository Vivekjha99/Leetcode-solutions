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
    TreeNode* buildTree(vector<int>&inorder,vector<int>& postorder,int &rootIdx,int s,int e){
        if(s>e)return NULL;
        int pivot=s;
        while(postorder[rootIdx]!=inorder[pivot])pivot++;
        rootIdx--;
        TreeNode* root=new TreeNode(inorder[pivot]);
        root->right=buildTree(inorder,postorder,rootIdx,pivot+1,e);
        root->left=buildTree(inorder,postorder,rootIdx,s,pivot-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        int rootIdx=n-1;
        return buildTree(inorder,postorder,rootIdx,0,n-1);
    }
};