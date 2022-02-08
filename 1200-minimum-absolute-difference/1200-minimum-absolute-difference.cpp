class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int diff=INT_MAX;
        for(int i=1;i<n;i++){
            diff=min(diff,nums[i]-nums[i-1]);
        }
        vector<vector<int>>ans;int idx=1;
        while(idx<n){
            if(nums[idx]-nums[idx-1]==diff){
                ans.push_back({nums[idx-1],nums[idx]});
            }
            idx++;
        }
        return ans;
    }
};