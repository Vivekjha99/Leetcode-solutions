class Solution {
public:
    int solve(int curr,int n,vector<int>&dp){
        if(curr>n)return 0;
        if(curr==n)return 1;
        if(dp[curr]!=-1)return dp[curr];
        return dp[curr]=solve(curr+1,n,dp)+solve(curr+2,n,dp);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return solve(0,n,dp);
    }
};