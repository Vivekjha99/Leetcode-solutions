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
    void findStrs(TreeNode* root,string s,string &res){
        if(root==NULL){
            return;
        }
        s=s+char('a'+root->val);
        if(root->left==NULL && root->right==NULL){
            reverse(s.begin(),s.end());
            if(res.empty()|| res>s){
                res=s;
            }
            //backtracking
            reverse(s.begin(),s.end());
        }
        findStrs(root->left,s,res);
        findStrs(root->right,s,res);
    }
    string smallestFromLeaf(TreeNode* root) {
        string res="";
        findStrs(root,"",res);
        return res;
    }
};