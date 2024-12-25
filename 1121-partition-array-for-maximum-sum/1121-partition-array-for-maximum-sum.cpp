class Solution {
public:
    int maxSumAfterPartitioning(vector<int>&arr,int i,int k,vector<int>&dp){
        if(i<=0)return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=0,currMax=0;
        for(int j=1;j<=k && i-j>=0;j++){
            currMax=max(currMax,arr[i-j]);
            ans=max(ans,j*currMax+maxSumAfterPartitioning(arr,i-j,k,dp));
        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,-1);
        return maxSumAfterPartitioning(arr,n,k,dp);
    }
};