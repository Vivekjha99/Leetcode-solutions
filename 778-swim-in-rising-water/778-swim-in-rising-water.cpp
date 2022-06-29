class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<vector<int>>vis(n,vector<int>(n,0));
        int ans=max(grid[0][0],grid[n-1][n-1]);
        pq.push({ans,0,0});
        vector<int>dir={1,0,-1,0,1};
        vis[0][0]=1;
        if(n==1)return ans;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            ans=max(ans,it[0]);
            for(int i=0;i<4;i++){
                int x=it[1]+dir[i];
                int y=it[2]+dir[i+1];
                if(x>=0 && x<n && y>=0 && y<n && vis[x][y]==0){
                    if(x==n-1 && y==n-1)return ans;
                    vis[x][y]=1;
                    pq.push({grid[x][y],x,y});
                }
            }
        }
        return -1;
    }
};