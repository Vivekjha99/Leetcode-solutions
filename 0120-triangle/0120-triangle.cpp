class Solution {
public:
    long getMinSum(vector<vector<int>>&arr,int i,int j,int n,vector<vector<int>>&dp){
        if(i>=n)return INT_MAX;
        if(i==n-1)return arr[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        long res=arr[i][j]+min(getMinSum(arr,i+1,j,n,dp),getMinSum(arr,i+1,j+1,n,dp));
        return dp[i][j]=res;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n+1);
        for(int i=0;i<n;i++){
            dp[i].resize(triangle[i].size(),-1);
        }
        return getMinSum(triangle,0,0,n,dp);
    }
};