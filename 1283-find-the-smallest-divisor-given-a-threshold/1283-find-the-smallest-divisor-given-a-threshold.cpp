class Solution {
public:
    bool check(vector<int>&nums,int k,int t){
        int res=0;
        for(auto x:nums){
            res+=ceil(1.0*x/k);
        }
       
        return res<=t;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(),nums.end());
        int l=1,r=nums.back();
   
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            
            if(check(nums,mid,threshold)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};