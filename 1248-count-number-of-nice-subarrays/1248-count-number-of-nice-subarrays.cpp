class Solution {
public:
    int atmost(vector<int>&nums,int k){
        int s=0,e=0;
        int res=0;
        while(e<nums.size()){
            k-=nums[e]%2;
            while(k<0)k+=nums[s++]&1;
            res+=e-s+1;
            e++;
        }
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};