class Solution {
public:
    void dfs(vector<vector<int>>&g,vector<bool>&vis,int &res,int x){
        if(!vis[x]){
            res++;
            vis[x]=true;
            for(auto child:g[x]){
                if(!vis[child])
                    dfs(g,vis,res,child);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bs) {
        int n=bs.size();
        vector<vector<int>>g(n);
        for(int i=0;i<n;i++){
            long long x=bs[i][0];
            long long y=bs[i][1];
            long long r=bs[i][2];
            for(int j=0;j<n;j++){
                if(i!=j){
                    long long dx=abs(bs[j][0]-x);
                    long long dy=abs(bs[j][1]-y);
                    if(dx*dx+dy*dy<=r*r)
                        g[i].push_back(j);
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int res=0;
            vector<bool>vis(n,false);
            dfs(g,vis,res,i);
            ans=max(ans,res);
        }
        return ans;
    }
};