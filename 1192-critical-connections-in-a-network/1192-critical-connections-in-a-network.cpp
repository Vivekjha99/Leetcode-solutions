class Solution {
public:
    unordered_map<int,vector<int>>g;
    void dfs(int u,vector<int>&low,vector<int>&par,vector<int>&disc,vector<vector<int>>&ans){
        static int time=0;
        disc[u]=low[u]=time;
        time+=1;
        for(auto v:g[u]){
            if(disc[v]==-1){
                par[v]=u;
                dfs(v,low,par,disc,ans);
                low[u]=min(low[u],low[v]);
                if(low[v]>disc[u]){
                    //bridge found
                    ans.push_back({u,v});
                }
            }
            else if(v!=par[u]){
                //backedge
                low[u]=min(low[u],disc[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>par(n,-1),low(n,-1),disc(n,-1);
        for(auto e:connections){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(disc[i]==-1){
                dfs(i,low,par,disc,ans);
            }
        }
        return ans;
    }
};