class Solution {
public:
    int solve(vector<vector<int>>&mat,int i,int j,int n,vector<vector<int>>&dp){
        if(i>=n || j>=n)return INT_MAX;
        if(i==n-1)return mat[i][j];
        if(dp[i][j]!=INT_MAX)return dp[i][j];
        int left=INT_MAX,down=INT_MAX,right=INT_MAX;
        if(i+1<n){
            if(j>0)left=solve(mat,i+1,j-1,n,dp);
            if(j<n-1)right=solve(mat,i+1,j+1,n,dp);
            down=solve(mat,i+1,j,n,dp);
        }
        return dp[i][j]=mat[i][j]+min(left,min(down,right));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans=INT_MAX;
        vector<vector<int>>dp(n+1,vector<int>(n+1,INT_MAX));
        for(int i=0;i<n;i++){
            ans=min(ans,solve(matrix,0,i,n,dp));
        }
        return ans;
    }
};