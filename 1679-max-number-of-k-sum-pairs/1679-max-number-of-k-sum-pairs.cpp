class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<n;i++){
            if(mp[k-nums[i]]>0){
                ans++;
                mp[nums[i]]=max(0,mp[nums[i]]-1);
                mp[k-nums[i]]=max(0,mp[k-nums[i]]-1);
            }
            else mp[nums[i]]++;
        }
        return ans;
    }
};