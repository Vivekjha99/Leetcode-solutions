class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        sort(nums.begin(),nums.end());
        int curr=1,ans=0;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1])continue;
            else if(nums[i]==nums[i-1]+1)curr++;
            else {
                ans=max(ans,curr);
                curr=1;
            }
        }
        return max(ans,curr);
    }
};