typedef pair<int ,pair<int,int>> ppi;
class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        priority_queue<ppi,vector<ppi>,greater<ppi>>pq;
        if(grid[0][1]>1 && grid[1][0]>1)return -1;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>time(n,vector<int>(m,INT_MAX));
        time[0][0]=0;
        pq.push({grid[0][0],{0,0}});
        vector<int>dir={1,0,-1,0,1};
        while(!pq.empty()){
            ppi p=pq.top();
            pq.pop();
            int ct=p.first;
            int x=p.second.first;
            int y=p.second.second;
            if(x==n-1 && y==m-1)return ct;
            for(int i=0;i<4;i++){
                int nx=x+dir[i];
                int ny=y+dir[i+1];
                if(nx<0 || nx>=n || ny<0 ||ny>=m)continue;
                int diff=grid[nx][ny]-ct;
                int newTime;
                if(grid[nx][ny]<=ct)newTime=ct+1;
                else{
                    if(diff%2)newTime=grid[nx][ny];
                    else newTime=grid[nx][ny]+1;
                }
                if(newTime<time[nx][ny]){
                    time[nx][ny]=newTime;
                    pq.push({newTime,{nx,ny}});
                }
            }
        }
        return -1;
    }
};