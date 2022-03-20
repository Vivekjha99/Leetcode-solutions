class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(n<=3){
            return 0;
        }
       return min({nums[n-1-3]-nums[0],nums[n-1]-nums[3],nums[n-3]-nums[1],nums[n-2]-nums[2]});
    }
};