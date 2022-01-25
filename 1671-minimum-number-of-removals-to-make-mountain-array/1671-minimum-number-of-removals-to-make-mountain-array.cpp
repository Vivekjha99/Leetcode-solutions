class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp1(n,1),dp2(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j])
                    dp1[i]=max(dp1[i],1+dp1[j]);
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(nums[i]>nums[j])
                dp2[i]=max(dp2[i],1+dp2[j]);
            }
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            if(dp1[i]>1 && dp2[i]>1)
            ans=max(ans,dp1[i]+dp2[i]-1);
        }
        // for(auto x:dp1)cout<<x<<" ";
        // cout<<endl;
        // for(auto x:dp2)cout<<x<<" ";
        // cout<<endl;
        // int res=*max_element(dp.begin(),dp.end());
        return n-ans;
    }
};