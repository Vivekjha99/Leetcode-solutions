class Solution {
public:
    int solve(vector<int>&nums,int cnt,int idx,int n,vector<vector<int>>&dp){
        if(idx>=n)return 0;
        if(dp[idx][cnt]!=-1)return dp[idx][cnt];
        int res=max(solve(nums,cnt,idx+1,n,dp),cnt*nums[idx]+solve(nums,cnt+1,idx+1,n,dp));
        return dp[idx][cnt]=res;
    }
    int maxSatisfaction(vector<int>& sat) {
        int n=sat.size();
        sort(sat.begin(),sat.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(sat,1,0,n,dp);
    }
};