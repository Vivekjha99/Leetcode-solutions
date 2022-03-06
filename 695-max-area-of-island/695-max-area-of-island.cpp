class Solution {
public:
    int n,m;
    void dfs(vector<vector<int>>&grid,int x,int y,int &res){
        grid[x][y]=0;
        res++;
        int dir[]={1,0,-1,0,1};
        for(int i=0;i<4;i++){
            int dx=x+dir[i];
            int dy=y+dir[i+1];
            if(dx>=0 && dx<n && dy>=0 && dy<m && grid[dx][dy]==1)dfs(grid,dx,dy,res);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    int res=0;
                    dfs(grid,i,j,res);
                    ans=max(ans,res);
                }
            }
        }
        return ans;
    }
};