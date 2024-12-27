class Solution {
public:
    // int solve(vector<vector<int>>&grid,int i,int j,int n,vector<vector<int>>&dp){
    //     if(i>=n || j>=n)return INT_MAX;
    //     if(i==n-1)return grid[i][j];
    //     if(dp[i][j]!=INT_MAX)return dp[i][j];
    //     int res=INT_MAX;
    //     for(int idx=0;idx<n;idx++){
    //         if(idx!=j)res=min(res,solve(grid,i+1,idx,n,dp));
    //     }
    //     return dp[i][j]=grid[i][j]+res;
    // }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=INT_MAX;
        // vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        // for(int i=0;i<n;i++){
        //     ans=min(ans,solve(grid,0,i,n,dp));
        // }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int res=INT_MAX;
                for(int k=0;k<n;k++){
                    if(k!=j)res=min(res,grid[i-1][k]);
                }
                grid[i][j]+=res;    
            }
        }
        for(int i=0;i<n;i++){
            ans=min(ans,grid[n-1][i]);
        }
        return ans;
    }
};