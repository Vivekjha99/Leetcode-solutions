class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>>g(n);
        for(auto &e:roads){
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
        }
        int res=0;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                res=g[i].size()+g[j].size();
                if(g[i].count(j))res--;
                ans=max(res,ans);
            }
            
        }
        return ans;
    }
};