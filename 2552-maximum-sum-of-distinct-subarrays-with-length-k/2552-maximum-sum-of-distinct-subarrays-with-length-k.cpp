class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0;long long currSum=0;
        int n=nums.size();if(n<k)return 0;
        unordered_map<int,int>mp;
        vector<long long>pref(n);pref[0]=nums[0];
        int i=0;
        while(i<k && i<nums.size()){
            mp[nums[i]]++;
            currSum+=nums[i++];
        }
        if(mp.size()==k)ans=currSum;
        while(i<nums.size()){
            mp[nums[i]]++;
            mp[nums[i-k]]--;
            if(mp[nums[i-k]]==0)mp.erase(nums[i-k]);
            currSum-=nums[i-k];
            currSum+=nums[i];
            if(mp.size()==k)ans=max(ans,currSum);
            i++;
        }
        return ans;
    }
};