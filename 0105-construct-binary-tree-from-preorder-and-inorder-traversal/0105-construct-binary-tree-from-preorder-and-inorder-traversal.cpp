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
    TreeNode* buildTree(vector<int>&preorder,vector<int>&inorder,int &rootIdx,int s,int e){
        if(s>e)return NULL;
        int pivot=s;
        //we are finding the point to break the inorder into subtree inorders
        while(preorder[rootIdx]!=inorder[pivot])pivot++;
        //as it will the root of the left subtree
        rootIdx++;
        TreeNode* root=new TreeNode(inorder[pivot]);
        root->left=buildTree(preorder,inorder,rootIdx,s,pivot-1);
        root->right=buildTree(preorder,inorder,rootIdx,pivot+1,e);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx=0;
        return buildTree(preorder,inorder,rootIdx,0,preorder.size()-1);
    }
};