class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=-1;
        int n=nums.size();
        for(int i=0;i<=nums[n-1];i++){
            int idx=lower_bound(nums.begin(),nums.end(),i)-nums.begin();
            if(n-idx==i){
                ans=i;
                break;
            }
        }
        return ans;
    }
};