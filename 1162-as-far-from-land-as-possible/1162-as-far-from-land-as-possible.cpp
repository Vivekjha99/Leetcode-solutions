class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>>q;
        int steps=0;
        vector<int>dir={1,0,-1,0,1};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int dx=i+dir[k];
                        int dy=j+dir[k+1];
                        q.push({dx,dy});
                    }
                }
            }
        }
        while(!q.empty()){
            int sz=q.size();
            steps++;
            while(sz--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(x>=0 && x<n && y>=0 && y<n &&grid[x][y]==0){
                    grid[x][y]=steps;
                     for(int i=0;i<4;i++){
                        int dx=x+dir[i];
                        int dy=y+dir[i+1];
                        q.push({dx,dy});
                    }
                }
                }
            }
            return steps==1?-1:steps-1;        
    }
};