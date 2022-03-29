class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto x:nums)mp[x]=1;
        for(int i=1;i<500005;i++){
            if(mp.count(i)==0)return i;
        }
        return 1;
    }
};