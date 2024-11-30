class Solution {
public:
void euler(vector<vector<int>>&ans,unordered_map<int,stack<int>>&adj,int curr){
    auto &st=adj[curr];
    while(!st.empty()){
        int v=st.top();
        st.pop();
        euler(ans,adj,v);
        ans.push_back({curr,v});
    }
}
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int m=pairs.size();//no of edges
        unordered_map<int,stack<int>>adj;
        unordered_map<int,int>ind;
        unordered_map<int,int>out;
        for(auto e:pairs){
            ind[e[1]]++;
            out[e[0]]++;
            adj[e[0]].push(e[1]);
        }
        int start=-1;
        for(auto &u:adj){
            int node=u.first;
            if(out[node]-ind[node]==1)start=node;
        }
        if(start==-1)start=adj.begin()->first;
        vector<vector<int>>ans;
        euler(ans,adj,start);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};