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
    int maxfreq=0,currfreq=0,prev=INT_MIN;
    vector<int>res;
    void solve(TreeNode* root){
        if(root==NULL)return;
        solve(root->left);
        if(prev==root->val)currfreq++;
        else currfreq=1;
        if(maxfreq<currfreq){
            maxfreq=currfreq;
            res.clear();
            res.push_back(root->val);
        }
        else if(maxfreq==currfreq){
            res.push_back(root->val);
        }
        prev=root->val;
        solve(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        solve(root);
        return res;
        
    }
};