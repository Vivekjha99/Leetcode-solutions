class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& nums) {
        int n=nums.size();
        int r=n-1;
        while(r>0 && nums[r-1]<=nums[r])r--;
        int res=r;
        for(int l=0;l<r && (l==0 || nums[l]>=nums[l-1]);l++){
            while(r<n && nums[l]>nums[r])r++;
            res=min(res,r-l-1);
        }
        return res;
    }
};