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
    TreeNode* findlca(TreeNode* root,int s,int d){
        if(root==NULL || root->val==s || root->val==d)
            return root;
        TreeNode* left=findlca(root->left,s,d);
        TreeNode* right=findlca(root->right,s,d);
        if(left && right)return root;
        return left==NULL?right:left;
    }
    int findstart(TreeNode* root,int x,int cnt){
        if(root==NULL)return 0;
        if(root->val==x)return cnt;
        int left=findstart(root->left,x,cnt+1);
        int right=findstart(root->right,x,cnt+1);
        return max(left,right);
    }
    bool finddest(TreeNode* root,int x,string &path){
        if(root==NULL)return false;
        if(root->val==x)return true;
        bool left=finddest(root->left,x,path);
        if(left)path.push_back('L');
        bool right=finddest(root->right,x,path);
        if(right)path.push_back('R');
        return left| right;
    }
    string getDirections(TreeNode* root, int s, int d) {
        TreeNode* lca=findlca(root,s,d);
        int dist=findstart(lca,s,0);
        string ans="";
        while(dist--)ans.push_back('U');
        string path="";
        finddest(lca,d,path);
        reverse(path.begin(),path.end());
        ans+=path;
        return ans;
    }
};