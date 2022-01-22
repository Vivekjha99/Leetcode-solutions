class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        int n=nums.size();
        for(auto x:nums)sum+=x;
        if(sum<x)return -1;
        sum-=x;
        if(sum==0)return n;
        int l=0;int res=0;
        int ans=0;
        for(int r=0;r<n;r++){
            res+=nums[r];
            while(l<r && res>sum){
                res-=nums[l++];
            }
            if(res==sum)
            ans=max(ans,r-l+1);
        }
        return ans>0?n-ans:-1;
    }
};