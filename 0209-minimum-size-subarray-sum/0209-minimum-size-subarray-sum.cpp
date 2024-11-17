class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        long currSum=0;
        int ans=INT_MAX;int i=0;
        for(int j=0;j<n;j++){
            target-=nums[j];
            while(target<=0){
                ans=min(ans,j-i+1);
                target+=nums[i++];
            }
        }
        return ans==INT_MAX?0:ans;
    }
};