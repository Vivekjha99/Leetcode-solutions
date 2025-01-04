class Solution {
public:
    // int solve(vector<int>&nums,int i,vector<int>&dp){
    //     if(i>=nums.size())return 0;
    //     if(dp[i]!=-1)return dp[i];
    //     int take=0,notTake=0;
    //     int nextIdx=upper_bound(nums.begin(),nums.end(),nums[i])-nums.begin();
    //     int sum=nums[i]*(nextIdx-i);
    //     //we cannot take nums[i]+1;
    //     int k=nextIdx;
    //     if(nextIdx<nums.size() && nums[nextIdx]==nums[i]+1){
    //         nextIdx=upper_bound(nums.begin(),nums.end(),nums[i]+1)-nums.begin();
    //     }
    //     take=sum+solve(nums,nextIdx,dp);
    //     notTake=solve(nums,k,dp);
    //     return dp[i]=max(take,notTake);
    // }
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(100005,0);
        sort(nums.begin(),nums.end());
        // return solve(nums,0,dp);
        vector<int>freq(100005,0);
        for(auto x:nums)freq[x]++;
        dp[1]=freq[1];
        for(int i=2;i<100001;i++){
            dp[i]=max(freq[i]*i+dp[i-2],dp[i-1]);
        }
        return dp[100000];
    }
};