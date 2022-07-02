class Solution {
public:
    unordered_map<int,vector<int>>g;
    unordered_map<int,bool>vis;
    int dfs(int node,int cost,vector<bool>&apple){
        if(vis[node]==true)return 0;
        vis[node]=true;
        int childcost=0;
        for(auto x:g[node]){
            childcost+=dfs(x,2,apple);
        }
        if(childcost==0 && !apple[node])return 0;
        return (childcost+cost);
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        for(auto &e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        return dfs(0,0,hasApple);
    }
};