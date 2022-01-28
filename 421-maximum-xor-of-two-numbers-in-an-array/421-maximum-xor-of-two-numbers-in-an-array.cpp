struct trienode{
    trienode* child[2];
};
class Solution {
public:
    trienode* insert(vector<int>&nums){
        trienode* root=new trienode();
        trienode* curr;
        for(auto num:nums){
            int val=num;curr=root;
            for(int j=31;j>=0;j--){
                int idx=(val>>j)&1;
                if(!curr->child[idx])curr->child[idx]=new trienode();
                curr=curr->child[idx];
            }
        }
        return root;
    }
    int helper(trienode* curr,int n){
        int res=0;
        for(int i=31;i>=0;i--){
            int idx=(n>>i)&1;
            idx=1-idx;
            if(curr->child[idx]){
                res+=1<<i;
                curr=curr->child[idx];
            }
            else
                curr=curr->child[1-idx];
        }
        return res;
    }
    int findMaximumXOR(vector<int>& nums) {
        trienode* root=insert(nums);
        int ans=0;
        for(auto x:nums){
            ans=max(ans,helper(root,x));
        }
        return ans;
    }
};