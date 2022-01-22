class Solution {
public:
    bool helper(vector<int>&nums,int k,int tar){
        int i=0,j=0,sum=0;
       while(i<k){
           sum+=nums[i++];
       }
        int maxi=sum;
        i=0;j=k;
        while(j<nums.size()){
            sum-=nums[i++];
            sum+=nums[j++];
            maxi=max(sum,maxi);
        }
        return maxi>=tar;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=0;
        int l=1,r=nums.size();
        while(l<=r){
            int mid=(l+r)>>1;
            if(helper(nums,mid,target)){
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};