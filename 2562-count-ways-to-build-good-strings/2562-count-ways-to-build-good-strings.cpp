class Solution {
public:
int mod=1e9+7;
    // int solve(int l, int h,int numZeros,int numOnes,int len,vector<int>&dp){
    //     if(len>h)return 0;
    //     if(dp[len]!=-1)return dp[len];
    //     int ans=0;
    //     if(len>=l && len<=h)ans=1;
    //      ans=(ans%mod+solve(l,h,numZeros,numOnes,len+numZeros,dp)%mod+solve(l,h,numZeros,numOnes,len+numOnes,dp)%mod)%mod;
    //     return dp[len]=ans%mod;
    // }
    int countGoodStrings(int low, int high, int zero, int one) {
        // vector<int>dp(high+1,-1);//dp[i]=no of good strings till length og i
        // return solve(low,high,zero,one,0,dp);
        vector<int>dp(high+1,0);
        dp[0]=1;//exactly one way to create a string of zero length
        for(int i=0;i<=high;i++){
            if(dp[i]==0)continue;
            if(i+zero<=high)dp[i+zero]=(dp[i+zero]+dp[i])%mod;
            if(i+one<=high)dp[i+one]=(dp[i+one]+dp[i])%mod;
        }
        int res=0;
        for(int i=low;i<=high;i++)res=(res+dp[i])%mod;
        return res;
       
    }
};