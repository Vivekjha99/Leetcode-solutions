/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int findSum(TreeNode* root, int res) {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return res * 10 + root->val;
        return findSum(root->left, res * 10 + root->val) +
               findSum(root->right, res * 10 + root->val);
    }
    int sumNumbers(TreeNode* root) {
        if (root == NULL)return 0;
            return findSum(root, 0);
    }
};