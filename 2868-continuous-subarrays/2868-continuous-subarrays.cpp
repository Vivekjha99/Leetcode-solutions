class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans=0;
        int st=0,en=0;
        int n=nums.size();
        map<int,int>mp;
        while(en<n){
            mp[nums[en]]++;
            while(mp.rbegin()->first-mp.begin()->first>2){
                mp[nums[st]]--;
                if(mp[nums[st]]==0)mp.erase(nums[st]);
                st++;
            }
            ans+=en-st+1;
            en++;
        }
        return ans;
    }
};