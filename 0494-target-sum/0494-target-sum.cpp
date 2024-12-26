class Solution {
public:
    int findSumWays(vector<int>&nums,int i,int res,int t){
        if(i>=nums.size()){
            if(res==t)return 1;
            else return 0;
        }
        return findSumWays(nums,i+1,res+nums[i],t)+findSumWays(nums,i+1,res-nums[i],t);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int res=0;
        return findSumWays(nums,0,0,target);

    }
};