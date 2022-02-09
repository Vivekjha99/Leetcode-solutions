class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        unordered_map<int,int>mp;
        for(auto x:nums)mp[x]+=1;
        for(auto x:mp){
            if((k>0 && mp.count(x.first+k))|| (k==0 && x.second>1))cnt++;
        }
        return cnt;
    }
};