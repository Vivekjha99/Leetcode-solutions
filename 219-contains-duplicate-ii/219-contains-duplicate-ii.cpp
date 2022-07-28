class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int>st;
        for(int i=0;i<nums.size();i++){
            if(st.size()>k)st.erase(nums[i-k-1]);
            if(st.find(nums[i])!=st.end())return true;
            st.insert(nums[i]);
        }
        return false;
    }
};