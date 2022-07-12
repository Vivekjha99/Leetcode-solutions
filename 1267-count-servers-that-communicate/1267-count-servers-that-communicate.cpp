class Solution {
public:
    void dfs(vector<vector<int>>&grid,int x,int y,vector<vector<int>>&vis,int &cnt){
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]==0 || vis[x][y]==1)return;
        vis[x][y]=1;
        cnt++;
        for(int i=0;i<grid[0].size();i++){
            if(grid[x][i]==1 && vis[x][i]==0)
                dfs(grid,x,i,vis,cnt);
        }
        for(int i=0;i<grid.size();i++){
            if(grid[i][y]==1 && vis[i][y]==0)
                dfs(grid,i,y,vis,cnt);
        }
        
    }
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    int cnt=0;
                    dfs(grid,i,j,vis,cnt);
                    ans+=(cnt==1?0:cnt);
                }
            }
        }
        return ans;
    }
};