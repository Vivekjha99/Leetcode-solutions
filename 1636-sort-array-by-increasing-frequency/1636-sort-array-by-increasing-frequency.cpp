class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,vector<int>>mp;
        map<int,int>freq;
        for(auto x:nums){
            freq[x]++;
        }
        for(auto [x,f]:freq){
            mp[f].push_back(x);
        }
        vector<int>ans;
        for(auto [f,v]:mp){
            sort(v.rbegin(),v.rend());
            int idx=0;
            while(idx!=v.size()){
                int freq=f;
                while(freq--)
                ans.push_back(v[idx]);
                idx++;
            }
        }
        return ans;
    }
};