class Solution {
public:
    int dp[52][52][52];
    vector<int> dir={1,0,-1,0,1};
    int mod=1e9+7;
    int solve(int n,int m,int k,int moves,int x,int y){
        if(x<0 || x>=n || y<0 || y>=m)return 1;
        if(moves==k)return 0;
        if(dp[x][y][moves]!=-1)return dp[x][y][moves];
        int res=0;
        for(int i=0;i<4;i++){
            res=(res+solve(n,m,k,moves+1,x+dir[i],y+dir[i+1]))%mod;
        }
        return dp[x][y][moves]=res;
    }
    int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return  solve(n,m,maxMove,0,startRow,startColumn);
    }
};