class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0];
        int sum=nums[0];
        //either take the current one or new sum
        for(int i=1;i<n;i++){
            ans=max(ans,sum);
            sum=max(sum+nums[i],nums[i]);
            // cout<<sum<<endl;
        }
        ans=max(ans,sum);
        return ans;
    }
};