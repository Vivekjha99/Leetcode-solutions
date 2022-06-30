class Solution {
public:
    int bfs(vector<vector<int>>&grid,int x,int y,int fx,int fy){
        if(x==fx && y==fy)return 0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        q.push({x,y});
        vector<int>dir={1,0,-1,0,1};
        int steps=0;
        while(!q.empty()){
            steps++;
            int sz=q.size();
            while(sz--){
                auto it=q.front();q.pop();
                for(int i=0;i<4;i++){
                    int dx=it.first+dir[i];
                    int dy=it.second+dir[i+1];
                    if(dx>=0 && dx<n && dy>=0 &&dy<m && vis[dx][dy]==0 && grid[dx][dy]!=0){
                        if(dx==fx && dy==fy)return steps;
                        q.push({dx,dy});
                        vis[dx][dy]=1;
                    }
                }
            }
        }
            return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        int n=forest.size();
        int m=forest[0].size();
        if(n==0 || m==0)return -1;
        vector<vector<int>>nums;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(forest[i][j]>1)
                    nums.push_back({forest[i][j],i,j});
            }
        }
        sort(nums.begin(),nums.end());
        int steps=0;
        int cstart=0,cend=0;
        for(int i=0;i<nums.size();i++){
            int res=bfs(forest,cstart,cend,nums[i][1],nums[i][2]);
            if(res==-1)return -1;
            steps+=res;
            cstart=nums[i][1];
            cend=nums[i][2];
        }
        return steps;
    }
};