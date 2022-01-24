class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1)return 1;
        vector<int>nums(n);
        nums[0]=1;
        int i=0,j=0,k=0;
        for(int idx=1;idx<n;idx++){
            nums[idx]=min(nums[i]*2,min(nums[j]*3,nums[k]*5));
            if(nums[idx]==2*nums[i])i++;
            if(nums[idx]==3*nums[j])j++;
            if(nums[idx]==5*nums[k])k++;
        }
        return nums[n-1];
    }
};