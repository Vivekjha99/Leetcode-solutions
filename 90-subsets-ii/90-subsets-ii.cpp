class Solution {
public:
    void solve(vector<int>&nums,int idx,vector<int>&v,vector<vector<int>>&res){
        res.push_back(v);
        for(int i=idx;i<nums.size();i++){
            if(i==idx || nums[i]!=nums[i-1]){
                v.push_back(nums[i]);
                solve(nums,i+1,v,res);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
     vector<vector<int>>res;
        vector<int>v;
        sort(nums.begin(),nums.end());
        solve(nums,0,v,res);
        return res;
    }
};