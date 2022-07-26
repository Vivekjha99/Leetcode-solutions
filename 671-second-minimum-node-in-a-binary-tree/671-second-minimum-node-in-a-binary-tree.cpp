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
    void solve(TreeNode* root,long long &a,long long &b){
        if(root==NULL)return;
        solve(root->left,a,b);
        if(root->val<a){
            b=a;
            a=root->val;
        }
        else if(root->val<b && root->val!=a){
            b=root->val;
        }
        solve(root->right,a,b);
    }
    int findSecondMinimumValue(TreeNode* root) {
        if(root==NULL)return -1;
        long long mini=1e10,smini=1e10;
        solve(root,mini,smini);
        return smini==1e10?-1:(int)smini;
    }
};