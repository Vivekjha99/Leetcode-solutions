class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long ans=-1e15;
        vector<long long>pref(n);
        pref[0]=nums[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
        }
        unordered_map<int,int>mp;
        mp[nums[0]]=0;
        for(int i=1;i<n;i++){
            long long t1=nums[i]+k;
            long long t2=nums[i]-k;
            if(mp.find(t1)!=mp.end()){
                long long csum=pref[i]-pref[mp[t1]]+nums[mp[t1]];
                ans=max(ans,csum);
            }
            if(mp.find(t2)!=mp.end()){
                long long csum=pref[i]-pref[mp[t2]]+nums[mp[t2]];
                ans=max(ans,csum);
            }
            if(mp.find(nums[i])!=mp.end()){
                if(pref[i]>=pref[mp[nums[i]]])continue;
            }
            mp[nums[i]]=i;
        }
        return ans==-1e15?0:ans;
    }
};