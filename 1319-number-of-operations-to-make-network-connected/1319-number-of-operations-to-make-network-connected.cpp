class Solution {
public:
    void dfs(int node,unordered_map<int,vector<int>>&g,vector<bool>&vis){
        vis[node]=true;
        for(auto child:g[node]){
            if(!vis[child])
                dfs(child,g,vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<bool>vis(n,false);
        unordered_map<int,vector<int>>g;
        int edges=connections.size();
        for(int i=0;i<connections.size();i++){
            g[connections[i][0]].push_back(connections[i][1]);
            g[connections[i][1]].push_back(connections[i][0]);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,g,vis);
            }
        }
        if(edges<n-1){
            return -1;
        }
        return cnt-1;
        
    }
};