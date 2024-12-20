class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,0);
        cost.push_back(0);
        dp[0]=cost[0];
        if(n==2)return min(cost[0],cost[1]);
        dp[1]=cost[1];
        for(int i=2;i<=n;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return dp[n];
    }
};