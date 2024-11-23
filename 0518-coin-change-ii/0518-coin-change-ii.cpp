class Solution {
public:
    int solve(int amt,vector<int>&coins,int idx,vector<vector<int>>&dp){
        if(idx>=coins.size() || amt<0)return 0;
        if(amt==0)return 1;
        if(dp[idx][amt]!=-1)return dp[idx][amt];
        int res=-1;
        if(coins[idx]>amt){
            res=solve(amt,coins,idx+1,dp);
        }
        else{
            res=solve(amt-coins[idx],coins,idx,dp)+solve(amt,coins,idx+1,dp);
        }
        return dp[idx][amt]=res;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(5002,-1));
        return solve(amount,coins,0,dp);
    }
};