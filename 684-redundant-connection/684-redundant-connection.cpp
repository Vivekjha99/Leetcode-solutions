class Solution {
public:
    int find(int x,vector<int>&par){
        if(par[x]==x)return x;
        return par[x]=find(par[x],par);
    }
    void unite(int x1,int x2,vector<int>&par,vector<int>&sz){
        x1=find(x1,par);
        x2=find(x2,par);
        if(x1==x2)return ;
        if(sz[x1]<=sz[x2]){
            sz[x2]+=sz[x1];
            par[x1]=x2;
        }
        else {
            sz[x1]+=sz[x2];
            par[x2]=x1;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       int n=edges.size();
        vector<int>par(n+1);
        vector<int>sz(n+1,1);
        for(int i=1;i<=n;i++)par[i]=i;
        vector<int>ans;
        for(auto x:edges){
            int p1=find(x[0],par);
            int p2=find(x[1],par);
            if(p1==p2){
                ans=x;
            }
            else{
                unite(x[0],x[1],par,sz);
            }
        }
        return ans;
    }
};