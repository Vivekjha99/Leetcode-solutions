class Solution {
public:
    void dfs(vector<vector<int>>&grid,int x,int y,int n,int m,vector<int>&res,vector<vector<bool>>&vis){
        res[0]=min(res[0],x);
        res[1]=min(res[1],y);
        res[2]=max(res[2],x);
        res[3]=max(res[3],y);
        vis[x][y]=true;
        vector<int>dir={1,0,-1,0,1};
        for(int i=0;i<4;i++){
            int dx=x+dir[i];
            int dy=y+dir[i+1];
            if(dx>=0 && dx<n && dy>=0 && dy<m && vis[dx][dy]==false && grid[dx][dy]==1)
                dfs(grid,dx,dy,n,m,res,vis);
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size();
        int m=land[0].size();
        if(n==1 && m==1){
            if(land[0][0]==0)return {};
            else return {{0,0,0,0}};
        }
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j] && !vis[i][j]){
                    vector<int>res={i,j,i,j};
                    dfs(land,i,j,n,m,res,vis);
                    ans.push_back(res);
                }
            }
        }
        return ans;
    }
};