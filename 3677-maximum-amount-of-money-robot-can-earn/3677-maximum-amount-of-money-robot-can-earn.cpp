class Solution {
public:
    int maxCoins(vector<vector<int>>&coins,int i,int j,int moves,int m,int n, vector<vector<vector<int>>>&dp){
        if(i>=m || j>=n)return INT_MIN;
        if(i==m-1 && j==n-1){
            if(moves>0 && coins[i][j]<0)return 0;
            else return coins[i][j];
        }
        if(dp[i][j][moves]!=INT_MIN)return dp[i][j][moves];
        int take=INT_MIN,notTake=INT_MIN;
        take=coins[i][j]+max(maxCoins(coins,i+1,j,moves,m,n,dp),maxCoins(coins,i,j+1,moves,m,n,dp));
        if(coins[i][j]<0 && moves>0){
            notTake=max(maxCoins(coins,i+1,j,moves-1,m,n,dp),maxCoins(coins,i,j+1,moves-1,m,n,dp));
        }
        return dp[i][j][moves]=max(take,notTake);
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int m=coins.size();
        int n=coins[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(3,INT_MIN)));
        return maxCoins(coins,0,0,2,m,n,dp);
    }
};