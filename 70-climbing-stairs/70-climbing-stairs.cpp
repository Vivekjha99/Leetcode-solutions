class Solution {
public:
    int func(int n,vector<int>&dp){
        if(n<=2)return n;
        if(dp[n]!=0)return dp[n];
        return dp[n]=func(n-2,dp)+func(n-1,dp);
    }
    int climbStairs(int n) {
        if(n<=2)return n;
        vector<int>dp(50,0);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        return func(n,dp);
        
    }
};