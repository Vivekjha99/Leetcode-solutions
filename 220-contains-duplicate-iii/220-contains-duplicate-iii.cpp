class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long >st;
        for(int i=0;i<nums.size();i++){
            long ele=nums[i];
            if(st.size()>k)st.erase(nums[i-k-1]);
            auto x=st.lower_bound(ele-t);
            if(x!=st.end() && *x-ele<=t)return true;
            st.insert(ele);
        }
        return false;
    }
};