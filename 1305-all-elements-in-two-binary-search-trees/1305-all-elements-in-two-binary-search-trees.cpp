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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*>st1,st2;
        vector<int>res;
        while(root1 || root2|| !st1.empty() || !st2.empty()){
            while(root1){
                st1.push(root1);
                root1=root1->left;
            }
            while(root2){
                st2.push(root2);
                root2=root2->left;
            }
            if(st2.empty()|| (!st1.empty() && (st1.top()->val<=st2.top()->val)))             {
                TreeNode *t=st1.top();
                st1.pop();
                res.push_back(t->val);
                root1=t->right;
            } 
            else{
                TreeNode *t=st2.top();
                st2.pop();
                res.push_back(t->val);
                root2=t->right;
                
            }
        }
        return res;
    }
};