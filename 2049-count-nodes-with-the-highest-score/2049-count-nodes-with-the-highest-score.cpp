class Solution {
public:
    int solve(vector<vector<int>>&g,int node,vector<int>&size){
        int ans=1;
        for(auto x:g[node]){
            ans+=solve(g,x,size);
        }
        return size[node]=ans;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        int n=parents.size();
        vector<int>size(n,0);//stores the size of the subtrees including the ith node itsef
        vector<vector<int>>g(n);
        for(int i=1;i<n;i++){
            g[parents[i]].push_back(i);
        }
        solve(g,0,size);
        //now for each node we will find the leftover nodes and then the ans
        long long ans=0,cnt=0;
        for(int i=0;i<n;i++){
            long long res=1;
            res=max(res,(long long)(n-size[i]));
            //sizes of subtrees of the ith node
            for(auto x:g[i]){
                res*=size[x];
            }
            if(res>ans){
                ans=res;
                cnt=1;
            }
            else if(res==ans){
                cnt++;
            }
        }
        return cnt;
    }
};