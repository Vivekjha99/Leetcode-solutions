class Solution {
public:
void dfs(int node,vector<vector<int>>&gr,vector<bool>&vis,vector<bool>&safeNodes){
    vis[node]=1;
    bool safe=true;
    for(auto ne:gr[node]){
        if(!vis[ne])
        dfs(ne,gr,vis,safeNodes);
        safe&=safeNodes[ne];
    }
    safeNodes[node]=safe;

}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>res;
        vector<bool>vis(n,false);
        vector<bool>safeNodes(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i])dfs(i,graph,vis,safeNodes);
        }
        for(int i=0;i<n;i++){
            if(safeNodes[i])res.push_back(i);
        }
        return res;
    }
};