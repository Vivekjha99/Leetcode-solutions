class Solution {
public:
    int solve(vector<int>&dp,vector<int>&cost,int idx){
        if(idx<0)return 0;
        if(idx<=1)return cost[idx];
        if(dp[idx]!=-1)return dp[idx];
        int left=solve(dp,cost,idx-1);
        int right=(idx>1)?solve(dp,cost,idx-2):INT_MAX;
        return dp[idx]=cost[idx]+min(left,right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return min(solve(dp,cost,n-1),solve(dp,cost,n-2));
    }
};