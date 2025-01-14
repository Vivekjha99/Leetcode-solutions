class Solution {
public:
    // int maxCoins(vector<vector<int>>&coins,int i,int j,int moves,int m,int n, vector<vector<vector<int>>>&dp){
    //     if(i>=m || j>=n)return INT_MIN;
    //     if(i==m-1 && j==n-1){
    //         if(moves>0 && coins[i][j]<0)return 0;
    //         else return coins[i][j];
    //     }
    //     if(dp[i][j][moves]!=INT_MIN)return dp[i][j][moves];
    //     int take=INT_MIN,notTake=INT_MIN;
    //     take=coins[i][j]+max(maxCoins(coins,i+1,j,moves,m,n,dp),maxCoins(coins,i,j+1,moves,m,n,dp));
    //     if(coins[i][j]<0 && moves>0){
    //         notTake=max(maxCoins(coins,i+1,j,moves-1,m,n,dp),maxCoins(coins,i,j+1,moves-1,m,n,dp));
    //     }
    //     return dp[i][j][moves]=max(take,notTake);
    // }
    int maximumAmount(vector<vector<int>>& coins) {
        int m=coins.size();
        int n=coins[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(3,INT_MIN)));
        // return maxCoins(coins,0,0,2,m,n,dp);
        dp[0][0][0]=coins[0][0];
        if(coins[0][0]<0){
            dp[0][0][1]=dp[0][0][2]=0;
        }
        else{
            dp[0][0][1]=dp[0][0][2]=dp[0][0][0];
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<3;k++){
                    if(i>0){
                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+coins[i][j]);
                        if(coins[i][j]<0 && k>0){
                            dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]);
                        }
                    }
                    if(j>0){
                        dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+coins[i][j]);
                        if(coins[i][j]<0 && k>0){
                            dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k-1]);
                        }
                    }
                }
            }
        }
        return max({dp[m-1][n-1][0],dp[m-1][n-1][1],dp[m-1][n-1][2]});
    }
};