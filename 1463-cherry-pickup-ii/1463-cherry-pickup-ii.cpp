class Solution {
public:
    int n,m;
    int dfs(int r,int c1,int c2,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
        if(r>=n || c1>=m ||c1<0 || r<0 ||c2<0 ||c2>=m)return 0;
        if(dp[r][c1][c2]!=-1)return dp[r][c1][c2];
        int res=0;
        if(r<n){
            res=grid[r][c1];
            int maxi=0;
            if(c1!=c2)res+=grid[r][c2];
            for(int i=c1-1; i<=c1+1;i++){
                for(int j=c2-1;j<=c2+1;j++){
                    maxi=max(maxi,dfs(r+1,i,j,grid,dp));
                }
            }
            res+=maxi;
            dp[r][c1][c2]=res;
        }
        return res;
    }
    int cherryPickup(vector<vector<int>>& grid) {
         n=grid.size();
         m=grid[0].size();
        //we will make a 3d dp array where dp[r][c1][c2] stores the max result if the two robots start from r c1 and r c2 to the last row
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
       int ans= dfs(0,0,m-1,grid,dp);
        return dp[0][0][m-1];
    }
};