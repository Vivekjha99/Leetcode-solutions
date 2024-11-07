class Solution {
public:
    int largestCombination(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(32,0);
        int ans=0;
        for(int i=0;i<32;i++){
            for(int j=0;j<n;j++){
                if((1<<i & nums[j])!=0)res[i]++;
            }
        ans=max(ans,res[i]);
    }
    return ans;
    }
};