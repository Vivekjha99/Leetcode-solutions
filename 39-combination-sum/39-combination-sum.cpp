class Solution {
public:
    void solve(vector<int>&nums,vector<vector<int>>&res,vector<int>&temp,int n,int idx,int k){
        if(k<0)return;
        if(k==0){
            res.push_back(temp);
            return;
        }
        for(int i=idx;i<n;i++){
            temp.push_back(nums[i]);
            solve(nums,res,temp,n,i,k-nums[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        int n=nums.size();
        solve(nums,res,temp,n,0,target);
        return res;
    }
};