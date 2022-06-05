class Solution {
public:
    int solve(vector<int>&prices,int idx,int flag,int n,vector<vector<int>>&dp){
        if(idx>=n)return 0;
        if(dp[idx][flag]!=-1)return dp[idx][flag];
        int profit=0;
        if(flag){
            profit=max(-prices[idx]+solve(prices,idx+1,0,n,dp),solve(prices,idx+1,1,n,dp));
        }
        else{
            profit=max(prices[idx]+solve(prices,idx+2,1,n,dp),solve(prices,idx+1,0,n,dp));
        }
        return dp[idx][flag]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(prices,0,1,n,dp);
    }
};