class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        if(n<3)return 0;
        int ans=0;
        for(int i=2;i<n;i++){
            if(nums[i-1]-nums[i-2]==nums[i]-nums[i-1])dp[i]=1+dp[i-1];
            ans+=dp[i];
        }
        return ans;
    }
};