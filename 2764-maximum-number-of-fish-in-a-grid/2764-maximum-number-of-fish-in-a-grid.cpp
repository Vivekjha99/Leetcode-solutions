class Solution {
public:
    vector<int>dir={1,0,-1,0,1};
    void dfs(vector<vector<int>>&grid,int i,int j,int &res){
        res+=grid[i][j];
        grid[i][j]=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int idx=0;idx<4;idx++){
            int nx=i+dir[idx];
            int ny=j+dir[idx+1];
            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]!=0){
                dfs(grid,nx,ny,res);
            }
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int maxi=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    int res=0;
                    dfs(grid,i,j,res);
                    maxi=max(maxi,res);
                }
            }
        }
        return maxi;
    }
};