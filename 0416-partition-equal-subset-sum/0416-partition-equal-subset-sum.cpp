class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();int sum=0;
        for(auto x:nums)sum+=x;
        if(sum%2)return false;sum/=2;
        vector<vector<int>>dp(n+1,vector<int>(sum+1));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=0;i<=sum;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                dp[i][j]=dp[i-1][j];
                if(nums[i-1]<=j)dp[i][j]|=dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][sum];

        }
};