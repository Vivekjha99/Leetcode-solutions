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
    vector<TreeNode*> solve(int s,int e){
        vector<TreeNode*>res;
        if(s>e){
            res.push_back(NULL);
            return res;
        }
        if(s==e){
            res.push_back(new TreeNode(s));
            return res;
        }
        for(int i=s;i<=e;i++){
            vector<TreeNode*>left=solve(s,i-1);
            vector<TreeNode*>right=solve(i+1,e);
            for(auto x:left){
                for(auto y:right){
                    TreeNode* root=new TreeNode(i);
                    root->left=x;
                    root->right=y;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
        
    }
};