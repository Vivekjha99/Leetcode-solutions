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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==NULL)return NULL;
        queue<TreeNode*>q;
        q.push(root);
        bool reversed=false;
        while(!q.empty()){
            int sz=q.size();
            vector<TreeNode*>arr(sz);
            for(int i=0;i<sz;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
                if(reversed){
                    arr[i]=curr;
                    if(i>=sz/2){
                        swap(arr[i]->val,arr[sz-1-i]->val);
                    }
                }
            }
            reversed=!reversed;
        }
        return root;
    }
};