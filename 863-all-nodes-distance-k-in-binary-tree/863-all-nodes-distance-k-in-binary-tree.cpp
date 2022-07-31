/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findpar(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&par){
        if(root==NULL)return;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left!=NULL){
                q.push(curr->left);
                par[curr->left]=curr;
            }
            if(curr->right!=NULL){
                q.push(curr->right);
                par[curr->right]=curr;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        if(root==NULL)return ans;
        unordered_map<TreeNode*,TreeNode*>par;
        findpar(root,par);
        //now we will run bfs from target
        queue<TreeNode*>q;
        q.push(target);
        int d=0;
        unordered_map<TreeNode*,bool>vis;
        vis[target]=true;
        while(!q.empty()){
            int sz=q.size();
            if(d++==k)break;
            for(int i=0;i<sz;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left]=true;
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right]=true;
                }
                if(par[curr] && !vis[par[curr]]){
                    q.push(par[curr]);
                    vis[par[curr]]=true;
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};