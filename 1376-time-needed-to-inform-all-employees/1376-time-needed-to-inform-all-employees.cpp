class Solution {
public:
    vector<int>adj[100005];
    int dfs(int node,vector<int>&time){
        int res=0;
       for(auto x:adj[node]){
            res=max(res,dfs(x,time));
        }
    return time[node]+res;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for(int i=0;i<n;i++){
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);
        }
        return dfs(headID,informTime);
    }
};