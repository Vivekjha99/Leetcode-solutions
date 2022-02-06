class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto x:nums)mp[x]=1;
        int idx=0;
        for(int i=-100;i<=100;i++){
            if(mp.count(i))nums[idx++]=i;
        }
        return mp.size();
    }
};