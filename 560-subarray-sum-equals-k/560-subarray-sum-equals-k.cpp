class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        int cnt=0;
        unordered_map<int,int>mp;
        mp[0]++;//for subarrays starting from o index
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            cnt+=mp[sum-k];
            mp[sum]++;
        }
        return cnt;
    }
};