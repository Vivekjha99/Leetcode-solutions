class Solution {
public:
    void solve(vector<int>&nums,int i,vector<vector<int>>&res){         
        if(i==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int st=i;st<nums.size();st++){
            swap(nums[i],nums[st]);
            solve(nums,i+1,res);
            swap(nums[i],nums[st]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>res;
        solve(nums,0,res);
        return res;
    }
};