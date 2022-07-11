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
    int maxSum=0;
    int dfs(TreeNode* root){
        if(!root)return 0;
        int sum=dfs(root->left)+dfs(root->right)+root->val;
        maxSum=max(maxSum,++mp[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int>ans;
        for(auto x:mp){
            if(x.second==maxSum)
                ans.push_back(x.first);
        }
        return ans;
    }
};