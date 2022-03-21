class Solution {
public:
    void dfs(vector<vector<int>>&g,vector<int>&res,vector<vector<int>>&ans,int curr){
        res.push_back(curr);
        if(curr==g.size()-1){
            ans.push_back(res);
        }
        else for(auto x:g[curr])
            dfs(g,res,ans,x);
        //backtrack
        res.pop_back();
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
       vector<vector<int>>ans;
        vector<int>res;
        dfs(graph,res,ans,0);
        return ans;
    }
};