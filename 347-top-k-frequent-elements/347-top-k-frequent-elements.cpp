class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto x:nums)mp[x]++;
        sort(nums.begin(),nums.end(),[&](int a,int b){
            return mp[a]>mp[b];
        });
        unordered_set<int>st;
        for(auto x:nums){
            st.insert(x);
            if(st.size()==k)break;
        }
        vector<int>ans(st.begin(),st.end());
        return ans;
    }
};