class Solution {
public:
int mod=1e9+7;
    int solve(int l, int h,int numZeros,int numOnes,int len,vector<int>&dp){
        if(len>h)return 0;
        if(dp[len]!=-1)return dp[len];
        int ans=0;
        if(len>=l && len<=h)ans=1;
         ans=(ans%mod+solve(l,h,numZeros,numOnes,len+numZeros,dp)%mod+solve(l,h,numZeros,numOnes,len+numOnes,dp)%mod)%mod;
        return dp[len]=ans%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1,-1);//dp[i]=no of good strings till length og i
        return solve(low,high,zero,one,0,dp);
       
    }
};