class Solution {
public:
    int solve(vector<vector<int>>&mat,int x,int y,int n,int m,vector<vector<int>>&dp){
        if(x>=n || y>=m)return 1e8;
        if(x==n-1 && y==m-1)return (mat[x][y]<=0)?1-mat[x][y]:1;
        if(dp[x][y]!=-1)return dp[x][y];
        int right=solve(mat,x,y+1,n,m,dp);
        int down=solve(mat,x+1,y,n,m,dp);
        int res=min(right,down)-mat[x][y];
        dp[x][y]=(res<=0)?1:res;
        return dp[x][y];
    }
    int calculateMinimumHP(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(mat,0,0,n,m,dp);
    }
};