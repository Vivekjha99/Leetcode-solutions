class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                    grid[i][j]=0;
                }
            }
        }
        
        vector<int>dir={1,0,-1,0,1};
        int h=0;
        while(!q.empty()){
            int sz=q.size();
            h++;
            while(sz--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int dx=x+dir[i];
                    int dy=y+dir[i+1];
                    if(dx<0 || dx>=n || dy<0 || dy>=m || vis[dx][dy]!=0)
                        continue;
                    grid[dx][dy]=h;
                    vis[dx][dy]=1;
                    q.push({dx,dy});
                }
            }
        }
     return grid;
    }
};