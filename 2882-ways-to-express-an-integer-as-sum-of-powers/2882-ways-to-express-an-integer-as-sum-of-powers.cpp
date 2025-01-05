class Solution {
public:
int mod=1e9+7;
    int findWays(int currNo,long currSum,int x,int n,vector<vector<long>>&dp){
        if(currSum==n)return 1;
        if(currNo>n || currSum>n)return 0;
        if(dp[currNo][currSum]!=-1)return dp[currNo][currSum];
        long valToAdd=pow(currNo,x);
        long take=findWays(currNo+1,currSum+valToAdd,x,n,dp);
        long notTake=findWays(currNo+1,currSum,x,n,dp);
        return dp[currNo][currSum]=(take+notTake)%mod;
    }
    int numberOfWays(int n, int x) {
        vector<vector<long>>dp(n+1,vector<long>(n+1,-1));
        //dp[i][j]=no of ways to get j sum  by first i integers
        return findWays(1,0,x,n,dp);
    }
};