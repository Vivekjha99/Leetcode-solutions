class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        int n=nums.size();
        int maxi=0;
        int ele=-1;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
            maxi=max(maxi,(int)mp[nums[i]].size());
        }
        int len=n;
        for(auto x:mp){
            vector<int>v=x.second;
            if(v.size()==maxi){
                len=min(len,v[maxi-1]-v[0]+1);
            }
        }
        return len;
        
    }
};