class Solution {
public:
    int solve(vector<vector<int>>&grid,int i,int j,int n,vector<vector<int>>&dp){
        if(i>=n || j>=n)return INT_MAX;
        if(i==n-1)return grid[i][j];
        if(dp[i][j]!=INT_MAX)return dp[i][j];
        int res=INT_MAX;
        for(int idx=0;idx<n;idx++){
            if(idx!=j)res=min(res,solve(grid,i+1,idx,n,dp));
        }
        return dp[i][j]=grid[i][j]+res;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            ans=min(ans,solve(grid,0,i,n,dp));
        }
        return ans;
    }
};