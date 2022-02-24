class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        unordered_map<int,int>mp;
        vector<int>pref(n,0);
        int sum=0;
        for(auto x:nums)sum=(sum+x)%p;
        sum%=p;
        if(sum==0)return 0;
        int curr=0;
        int res=n;
        mp[0]=-1;
        for(int i=0;i<n;i++){
         curr=(curr+nums[i])%p;
            mp[curr]=i;
            int b=(curr-sum+p)%p;
            if(mp.find(b)!=mp.end())res=min(res,i-mp[b]);
        }
        return res==n?-1:res;
    }
};