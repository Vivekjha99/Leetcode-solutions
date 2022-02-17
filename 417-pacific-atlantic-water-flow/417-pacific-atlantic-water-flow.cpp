class Solution {
public:
    vector<vector<int>>res;
    void pacific(vector<vector<int>>&mat,int x,int y,vector<vector<int>>&grid){
        int r=mat.size();
        int c=mat[0].size();
        if(grid[x][y]==1)return;
        grid[x][y]=1;
        vector<int>dx={1,0,-1,0};
        vector<int>dy={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && nx<r && ny>=0 && ny<c && mat[nx][ny]>=mat[x][y]){
                pacific(mat,nx,ny,grid);
            }
        }
    }
     void atlantic(vector<vector<int>>&mat,int x,int y,vector<vector<int>>&grid){
        int r=mat.size();
        int c=mat[0].size();
        if(grid[x][y]==1)res.push_back({x,y});
        if(grid[x][y]==2)return;
         grid[x][y]=2;
        vector<int>dx={1,0,-1,0};
        vector<int>dy={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && nx<r && ny>=0 && ny<c && mat[nx][ny]>=mat[x][y]){
                atlantic(mat,nx,ny,grid);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) {
        int r=mat.size();
        if(r==0)return res;
        int c=mat[0].size();
        vector<vector<int>>grid(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i==0 || j==0)
                    pacific(mat,i,j,grid);
            }
        }
        for(int i=r-1;i>=0;i--){
            for(int j=c-1;j>=0;j--){
                if(i==r-1 || j==c-1)
                    atlantic(mat,i,j,grid);
            }
        }
        return res;
    }
};