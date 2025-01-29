class dsu{
    public:
    int n;
    vector<int>sz,par;
    dsu(int n){
        this->n=n;
        sz=vector<int>(n,1);
        par=vector<int>(n);
        for(int i=0;i<n;i++){
            par[i]=i;
        }   
    }
    int findPar(int a){
        if(par[a]==a)return a;
        return par[a]=findPar(par[a]);
    }
    void unite(int a,int b){
        int pa=findPar(a);
        int pb=findPar(b);
        if(pa==pb)return;
        if(sz[pa]>=sz[pb]){
            par[pb]=pa;
            sz[pa]+=sz[pb];
        }
        else{
            par[pa]=pb;
            sz[pb]+=sz[pa];
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        dsu ds(n+1);
        for(auto e:edges){
            int p1=ds.findPar(e[0]);
            int p2=ds.findPar(e[1]);
            if(p1==p2)return e;
            ds.unite(e[0],e[1]);
        }
        return {};
    }
};