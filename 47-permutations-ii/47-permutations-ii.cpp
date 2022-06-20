class Solution {
public:
    void solve(vector<int>&nums,int idx,int n,vector<vector<int>>&ans){
        if(idx==n){
            ans.push_back(nums);
            return;
        }
        unordered_set<int>st;
        for(int i=idx;i<n;i++){
            if(st.find(nums[i])!=st.end())continue;
            st.insert(nums[i]);
            swap(nums[i],nums[idx]);
            solve(nums,idx+1,n,ans);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        solve(nums,0,n,ans);
        return ans;
    }
};