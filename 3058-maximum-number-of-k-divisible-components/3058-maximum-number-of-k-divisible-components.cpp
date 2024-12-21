class Solution {
public:
    long long dfs(unordered_map<int,vector<int>>&mp,int src,vector<int>&values,int &ans,int k,vector<int>&vis){
        vis[src]=1;
        long long sum=values[src];
        for(auto child:mp[src]){
            if(vis[child])continue;
            sum+=dfs(mp,child,values,ans,k,vis);
            sum%=k;
        }
        if(sum%k==0){
            ans++;
            return 0;
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        unordered_map<int,vector<int>>mp;
        vector<int>vis(n,0);
        for(auto e:edges){
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }
        int ans=0;
        dfs(mp,0,values,ans,k,vis);
return ans;

    }
};