class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
            mp[nums[i]]++;
        int ans=0;
        for(auto x:mp){
            int c=x.second;
            ans+=(c*(c-1))/2;
        }
        return ans;
    }
};