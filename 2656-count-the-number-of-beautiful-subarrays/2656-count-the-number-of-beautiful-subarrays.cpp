class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long res=0;
        int n=nums.size();
        int val=0;
        unordered_map<int,int>mp;
        mp[0]++;
        for(int i=0;i<n;i++){
            val^=nums[i];
            if(mp.find(val)!=mp.end())res+=mp[val];
            mp[val]++;
        }
        return res;
    }
};