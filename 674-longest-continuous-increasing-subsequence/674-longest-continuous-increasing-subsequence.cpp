class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)return n;
        int len=0;
        for(int i=1;i<n;i++){
            int start=i-1;
            while(i<n && nums[i-1]<nums[i])i++;
            len=max(len,i-start);
        }
        return len;
    }
};