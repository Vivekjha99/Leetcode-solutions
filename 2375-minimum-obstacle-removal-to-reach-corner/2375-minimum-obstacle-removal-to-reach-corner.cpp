class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>dir={1,0,-1,0,1};
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        dist[0][0]=0;
        deque<pair<int,int>>q;
        q.push_front({0,0});
        while(!q.empty()){
            auto curr=q.front();
            q.pop_front();
            int x=curr.first;
            int y=curr.second;
            for(int i=0;i<4;i++){
                int nx=x+dir[i];
                int ny=y+dir[i+1];
                if(nx>=0 && nx<n &&ny>=0 && ny<m){
                    if(!vis[nx][ny]){
                        dist[nx][ny]=dist[x][y]+grid[nx][ny];
                        if(grid[nx][ny])q.push_back({nx,ny});
                        else q.push_front({nx,ny});
                        vis[nx][ny]=1;
                    }
                }
            }
        }
        return dist[n-1][m-1];

    }
};