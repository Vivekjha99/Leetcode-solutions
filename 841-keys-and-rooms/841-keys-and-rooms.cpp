class Solution {
public:
    unordered_map<int,vector<int>>adj;
    void dfs(int node,vector<int>&vis){
        vis[node]=1;
        cout<<node<<" ";
        for(auto x:adj[node]){
            if(vis[x]==0)
                dfs(x,vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<rooms[i].size();j++){
                adj[i].push_back(rooms[i][j]);
                // adj[rooms[i][j]].push_back(i);
            }
        }
        vector<int>vis(n,0);
        dfs(0,vis);
        for(auto x:vis){
            if(x==0)return false;
        }
        return true;
    }
};