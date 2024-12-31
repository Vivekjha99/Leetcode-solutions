class Solution {
public:
    // int solve(int curr,int n,vector<int>&dp){
    //     if(curr>n)return 0;
    //     if(curr==n)return 1;
    //     if(dp[curr]!=-1)return dp[curr];
    //     return dp[curr]=solve(curr+1,n,dp)+solve(curr+2,n,dp);
    // }
    int climbStairs(int n) {
        vector<int>dp(n+1,0);
        // return solve(0,n,dp);
       dp[0]=dp[1]=1;
       for(int i=2;i<=n;i++)dp[i]=dp[i-1]+dp[i-2];
        return dp[n];
    }
};