class Solution {
public:
void solve(vector<int>&nums,int idx,vector<vector<int>>&res){
    if(idx==nums.size()){
        res.push_back(nums);
        return;
    }
    unordered_set<int>st;
    for(int i=idx;i<nums.size();i++){
        if(st.find(nums[i])!=st.end())continue;
        st.insert(nums[i]);
        swap(nums[i],nums[idx]);
        solve(nums,idx+1,res);
        swap(nums[i],nums[idx]);
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>v;
        solve(nums,0,res);
        return res;
    }
};