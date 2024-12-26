class Solution {
public:
    int mod = 1e9 + 7;
    int numberOfWays(int n, int x) 
    {
        int maxNum = 1;
        while (pow(maxNum, x) <= n) {
            maxNum++;
        }
        maxNum--;
        vector<vector<int>>dp(n+1,vector<int>(maxNum+1,0));
        for(int i=0;i<=maxNum;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=maxNum;j++){
                dp[i][j]=dp[i][j-1];
                if(i>=pow(j,x))dp[i][j]=(dp[i][j]+dp[i-pow(j,x)][j-1])%mod;
            }
        }
        return dp[n][maxNum];
        
    }
};