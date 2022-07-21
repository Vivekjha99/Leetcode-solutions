class Solution {
public:
    vector<int>dir={1,0,-1,0,1};
    int n,m;
    int bfs(vector<vector<char>>&maze,int x,int y){
        queue<pair<int,int>>q;
        q.push({x,y});
        maze[x][y]='+';
        int d=0;
        while(!q.empty()){
            int sz=q.size();
            d++;
            while(sz--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int dx=i+dir[k];
                    int dy=j+dir[k+1];
                    if(dx<0 || dx>=n || dy<0 || dy>=m || maze[dx][dy]=='+')
                        continue;
                    if(dx==0 || dx==n-1 || dy==0 || dy==m-1)
                        return d;
                        maze[dx][dy]='+';
                        q.push({dx,dy});
  
                }
            }
        }
        return -1;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& ent) {
        n=maze.size();
        m=maze[0].size();
        return bfs(maze,ent[0],ent[1]);
    }
};