class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n=accounts.size();
        int m=accounts[0].size();
        int ans=0;
        for(auto &v:accounts){
            for(int i=1;i<v.size();i++){
                v[i]+=v[i-1];
            }
            ans=max(ans,v.back());
        }
        return ans;
    }
};