class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>>dp(k+2,vector<int>(n,INT_MAX));
        //reaching jth city using atmost i stops
        for(int i=0;i<=k+1;i++)
            dp[i][src]=0;
        for(int i=1;i<=k+1;i++){
            for(auto &v:flights){
                int u=v[0];
                int v1=v[1];
                int w=v[2];
                if(dp[i-1][u]!=INT_MAX){
                    dp[i][v1]=min(dp[i-1][u]+w,dp[i][v1]);
                }
            }
        }
        return (dp[k+1][dst]==INT_MAX)?-1:dp[k+1][dst];
        
    }
};