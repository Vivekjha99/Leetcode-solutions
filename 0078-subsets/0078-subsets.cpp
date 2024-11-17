class Solution {
public:
    void solve(vector<int>nums,int idx,int n ,vector<int>&res,vector<vector<int>>&ans){
        if(idx==n){
            ans.push_back(res);
            return;
        }
        // while(idx>0 && idx<n && nums[idx]==nums[idx]-1)idx++;
        res.push_back(nums[idx]);
        solve(nums,idx+1,n,res,ans);
        res.pop_back();
        solve(nums,idx+1,n,res,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>res;
        int n=nums.size();
        solve(nums,0,n,res,ans);
        return ans;
    }
};