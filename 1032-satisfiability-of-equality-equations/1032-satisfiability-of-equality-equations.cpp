class Solution {
public:
    int findPar(int a,vector<int>&par){
        if(a==par[a])return a;
        return findPar(par[a],par);
    }
    void unite(int a,int b,vector<int>&sz,vector<int>&par){
        int parA=findPar(a,par);
        int parB=findPar(b,par);
        if(sz[parA]>sz[parB]){
            sz[parA]+=sz[parB];
            par[parB]=par[parA];
        }
        else{
            sz[parB]+=sz[parA];
            par[parA]=par[parB];
        }
    }
    bool equationsPossible(vector<string>& equations) {
        vector<string>equals,unEquals;
        for(auto s:equations){
            if(s[1]=='=' && s[2]=='=')equals.push_back(s);
            else unEquals.push_back(s);
        }
        vector<int>par(26,0);
        for(int i=0;i<26;i++)par[i]=i;
        vector<int>sz(26,1);
        for(auto eq:equals){
            int a=eq[0]-'a';
            int b=eq.back()-'a';
            int parA=findPar(a,par);
            int parB=findPar(b,par);
            if(parA==parB)continue;
            unite(a,b,sz,par);
        }
        for(auto eq:unEquals){
            int a=eq[0]-'a';
            int b=eq.back()-'a';
             int parA=findPar(a,par);
            int parB=findPar(b,par);
            if(parA==parB)return false;
        }
        return true;

    }
};