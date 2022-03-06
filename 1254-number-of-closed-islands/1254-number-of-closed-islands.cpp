class Solution {
public:
    int n,m;
    void dfs(vector<vector<int>>&grid,int x,int y){
        grid[x][y]=-1;
        int dir[]={1,0,-1,0,1};
        for(int i=0;i<4;i++){
            int dx=x+dir[i];
            int dy=y+dir[i+1];
            if(dx>=0 && dx<n && dy>=0 && dy<m && grid[dx][dy]==0)
                dfs(grid,dx,dy);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        //making boundry islands invalid
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || i==n-1 || j==0 || j==m-1) && grid[i][j]==0)
                    dfs(grid,i,j);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};