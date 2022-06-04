class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& nums) {
        int n=nums.size();
        int maxendgain=INT_MIN;
        int ans=INT_MIN;
        for(int i=n-2;i>=0;i--){
            maxendgain=max(maxendgain,nums[i+1]-(i+1));
            ans=max(ans,maxendgain+nums[i]+i);
        }
        return ans;
    }
};