class Solution {
public:
    unordered_map<int,vector<int>>adj;
    void dfs(int node,vector<int>&vis,long long &cnt){
        vis[node]=1;
        cnt++;
        for(auto x:adj[node]){
            if(!vis[x])
                dfs(x,vis,cnt);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        long long ans=((long long)n*(n-1)/2);
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            long long cnt=0;
            if(!vis[i]){
                dfs(i,vis,cnt);
                ans-=(long long)(cnt*(cnt-1))/2;
            }
        }
        return ans;
    }
};