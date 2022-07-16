class Solution {
public:
    double solve(int n,int k,int x,int y,vector<vector<vector<double>>>&dp){
        if(x<0 || x>=n || y<0 || y>=n)return 0;
        if(k==0)return 1;
        if(dp[x][y][k]!=-1)return dp[x][y][k];
        double total=solve(n,k-1,x-2,y-1,dp)+
            solve(n,k-1,x-2,y+1,dp)+
            solve(n,k-1,x+2,y-1,dp)+
            solve(n,k-1,x+2,y+1,dp)+
            solve(n,k-1,x-1,y-2,dp)+
            solve(n,k-1,x-1,y+2,dp)+
            solve(n,k-1,x+1,y-2,dp)+
            solve(n,k-1,x+1,y+2,dp);
        double res=total/8.0;
        return dp[x][y][k]=res;
    }
    double knightProbability(int n, int k, int row, int col) {
        vector<vector<vector<double>>>dp(n+1,vector<vector<double>>(n,vector<double>(k+1,-1)));
        return solve(n,k,row,col,dp);
    }
};