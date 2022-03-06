class Solution {
public:
    int countOrders(int n) {
        vector<long long>dp(501);
        dp[1]=(long long)1;
        dp[2]=(long long)6;
        int mod=1e9+7;
        for(long long  i=3;i<=n;i++){
            long long x=i*2-1;
            long long p=(x*(x+1)/2)%mod;
            dp[i]=(dp[i-1]*p)%mod;
        }
        return dp[n]%mod;
    }
};