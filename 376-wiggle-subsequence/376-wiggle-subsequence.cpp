class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<int>inc(n,1),dec(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j])inc[i]=max(inc[i],dec[j]+1);
                if(nums[i]<nums[j])dec[i]=max(inc[j]+1,dec[i]);
            }
        }
        return max(dec.back(),inc.back());
    }
};