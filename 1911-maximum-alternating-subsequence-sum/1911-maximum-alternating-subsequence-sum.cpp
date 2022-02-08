class Solution {
public:
    
    long long solve(int idx,int flag,vector<int>&nums,vector<vector<long long>>&dp){
        if(idx==nums.size())return 0;
        if(dp[idx][flag]!=INT_MIN)return dp[idx][flag];
        return dp[idx][flag]=max(solve(idx+1,flag,nums,dp),(flag==1?nums[idx]:-nums[idx])+solve(idx+1,1-flag,nums,dp));
    }
    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long>>dp(100005,vector<long long>(2,INT_MIN));
        return solve(0,1,nums,dp);
        //1 is addition
    }
};