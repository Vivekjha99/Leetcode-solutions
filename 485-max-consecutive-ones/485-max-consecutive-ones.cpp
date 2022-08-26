class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int cnt=nums[0];
        int ans=0;
        for(int i=1;i<n;i++){
            if(nums[i]==1 && nums[i-1]==1)cnt++;
            else{
                ans=max(ans,cnt);
                cnt=nums[i]==1;
            }
        }
        ans=max(ans,cnt);
        return ans;
    }
};