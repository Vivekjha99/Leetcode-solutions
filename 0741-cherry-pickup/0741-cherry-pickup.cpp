class Solution {
public:
    int cherryPickup(vector<vector<int>>&grid,int n,int r1,int c1,int r2,int c2,vector<vector<vector<vector<int>>>>&dp){
        if(r1>=n || c1>=n || r2>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1)return INT_MIN;
        if(dp[r1][c1][r2][c2]!=-1)return dp[r1][c1][r2][c2];
        if(r1==n-1 && c1==n-1)return grid[r1][c1];
        if(r2==n-1 && c2==n-1)return grid[r2][c2];
        int cherries;
        if(r1==r2 && c1==c2){
            cherries=grid[r1][c1];
        }
        else{
            cherries=grid[r1][c1]+grid[r2][c2];
        }
        return dp[r1][c1][r2][c2]=cherries+max({cherryPickup(grid,n,r1+1,c1,r2+1,c2,dp),cherryPickup(grid,n,r1+1,c1,r2,c2+1,dp),cherryPickup(grid,n,r1,c1+1,r2+1,c2,dp),cherryPickup(grid,n,r1,c1+1,r2,c2+1,dp)});
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<vector<int>>>>dp(n,vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,-1))));
        return max(0,cherryPickup(grid,n,0,0,0,0,dp));
    }

};