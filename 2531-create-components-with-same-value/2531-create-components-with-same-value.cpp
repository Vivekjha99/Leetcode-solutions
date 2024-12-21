class Solution {
public:
    int dfs(unordered_map<int,vector<int>>&g,int src,int tar,vector<int>&nums,vector<int>&vis){
        vis[src]=nums[src];
        for(auto child:g[src]){
            if(vis[child])continue;
            vis[src]+=dfs(g,child,tar,nums,vis);
            if(vis[src]>tar)return 1e7;
        }
        //as we have found a tar sum subtree we will break it and not send any sum from this subtree to its parent.
        if(vis[src]==tar)return 0;
        return vis[src];
    }
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int sum=0;int n=nums.size();
        unordered_map<int,vector<int>>g;
        for(auto &e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        if(count(nums.begin(),nums.end(),nums[0])==n)return n-1;
        for(auto x:nums)sum+=x;
        for(int i=n;i>1;i--){
            if(sum%i)continue;
            int target=sum/i;
            vector<int>vis(n,0);
            if(dfs(g,0,target,nums,vis)==0)return i-1;
        }
        return 0;
    }
};