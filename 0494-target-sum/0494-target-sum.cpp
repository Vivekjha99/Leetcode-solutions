class Solution {
public:
int buffer=1000;
    int findSumWays(vector<int>&nums,int i,int res,int t,vector<vector<int>>&dp){
        if(i>=nums.size()){
            return res==t;
        }
        if(dp[i][res+buffer]!=-1)return dp[i][res+buffer];
        return dp[i][res+buffer]=findSumWays(nums,i+1,res+nums[i],t,dp)+findSumWays(nums,i+1,res-nums[i],t,dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(3002,-1));
        return findSumWays(nums,0,0,target,dp);

    }
};