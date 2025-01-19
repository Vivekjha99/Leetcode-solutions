class Solution {
public:
    int trapRainWater(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        //putting the boundaries
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!(i==0 || i==m-1 || j==0 || j==n-1) )continue;
                pq.push({grid[i][j],i*n+j});
                vis[i][j]=true;
            }
        }
        vector<int>dir={1,0,-1,0,1};
        int res=0;int maxH=INT_MIN;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int h=curr.first;
            int x=curr.second/n;
            int y=curr.second%n;
            maxH=max(maxH,h);
            for(int i=0;i<4;i++){
                int nx=x+dir[i];
                int ny=y+dir[i+1];
                if(nx<0 || nx>=m || ny<0 || ny>=n || vis[nx][ny])continue;
                vis[nx][ny]=true;;
                if(grid[nx][ny]<maxH)res+=maxH-grid[nx][ny];
                pq.push({grid[nx][ny],nx*n+ny});

            }
        }
        return res;
    }
};