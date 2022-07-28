class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int i=0;
        int ans=0;
        vector<int>pref(n,0);
        pref[0]=nums[0];
        for(int i=1;i<n;i++)pref[i]+=nums[i]+pref[i-1];
        for(int j=0;j<n;j++){
            mp[nums[j]]++;
            if(mp[nums[j]]>1){
                while(i<=j && mp[nums[j]]>1){
                    mp[nums[i++]]--;
                }
            }
            int sum=(i==0)?0:pref[i-1];
            sum=pref[j]-sum;
            ans=max(ans,sum);
        }
        return ans;
    }
};