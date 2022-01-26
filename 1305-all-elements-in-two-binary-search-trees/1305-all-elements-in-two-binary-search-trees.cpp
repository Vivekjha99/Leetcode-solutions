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
    void preorder(TreeNode* root,vector<int>&res){
        if(root==NULL)return;
        preorder(root->left,res);
        res.push_back(root->val);
        preorder(root->right,res);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>res1,res2,res;
        preorder(root1,res1);
        preorder(root2,res2);
        int i=0,j=0;
        while(i<res1.size() && j<res2.size()){
            if(res1[i]<=res2[j]){
                res.push_back(res1[i]);
                i++;
            }
            else{
                res.push_back(res2[j]);
                j++;
            }
        }
        while(i<res1.size())res.push_back(res1[i++]);
        while(j<res2.size())res.push_back(res2[j++]);
        return res;
    }
};