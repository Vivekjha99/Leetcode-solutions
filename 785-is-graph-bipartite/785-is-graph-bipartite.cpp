class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>>mp;
        int n=graph.size();
        for(int i=0;i<n;i++){
            for(auto &x:graph[i]){
                mp[i].push_back(x);
            }
        }
        queue<int>q;
        vector<int>vis(n+1,0);
        for(int i=0;i<n;i++){
            if(vis[i])continue;
            vis[i]=1;
            q.push(i);
            while(!q.empty()){
                int u=q.front();
                for(auto x:mp[u]){
                    if(!vis[x]){
                        q.push(x);
                        vis[x]=-vis[u];
                    }
                    else if(vis[x]==vis[u])return false;
                }
                q.pop();
            }
        }
        return true;
    }
};