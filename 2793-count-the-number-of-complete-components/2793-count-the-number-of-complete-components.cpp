class DSU{
    public:
    vector<int>sz;
    vector<int>par;
        DSU(int n){
            sz=vector<int>(n,1);
            par=vector<int>(n,-1);
            for(int i=0;i<n;i++)par[i]=i;
        }
        int findPar(int node){
            if(node==par[node])return node;
            //path compression
            return par[node]=findPar(par[node]);
        }
        void uniteNodes(int a,int b){
            int parA=findPar(a);
            int parB=findPar(b);
            if(parA==parB)return;
            if(sz[parA]>=sz[parB]){
                par[parB]=parA;
                sz[parA]+=sz[parB];
            }
            else{
                par[parA]=parB;
                sz[parB]+=sz[parA];
            }
        }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        vector<int>edgesCnt(n,0);
        for(auto e:edges){
           dsu.uniteNodes(e[0],e[1]);
           //now both are in the same component and have same parents
           int parOfComp=dsu.findPar(e[0]);
           edgesCnt[parOfComp]+=2;//since undirected
        }
       //now we will check if the no of edges=n*(n-1)/2
       int res=0;
       for(int i=0;i<n;i++){
        if(dsu.findPar(i)==i){
            //par found
            int nodes=dsu.sz[i];
            if(edgesCnt[i]==nodes*(nodes-1))res++;
        }
       }
       return res;
    }
};