class Solution {
public:
    int n,m;
    void dfs(vector<vector<int>>&grid2,vector<vector<int>>&grid1,int x,int y,bool &res){
        if(x<0 || x>=n || y<0 || y>=m )
            return ;
       if(grid1[x][y] == 0 && grid2[x][y] == 1) {
            res = false;
        }
            if(grid2[x][y]==0)return;
        grid2[x][y]=0;
        int dir[]={1,0,-1,0,1};
        for(int i=0;i<4;i++){
            int dx=x+dir[i];
            int dy=y+dir[i+1];
            dfs(grid2,grid1,dx,dy,res);
            }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n=grid2.size();
        m=grid2[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1){
                    bool flag=true;
                    dfs(grid2,grid1,i,j,flag);
                    ans+=flag;
                }
            }
        }
        return ans;
    }
};