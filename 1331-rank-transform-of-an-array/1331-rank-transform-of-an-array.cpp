class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        if(n==0)return {};
        vector<pair<int,int>>nums(n);
        for(int i=0;i<n;i++){
            nums[i]={arr[i],i};
        }
        sort(nums.begin(),nums.end());
        int rank=1;
        vector<int>ans(n);
        ans[nums[0].second]=1;
        for(int i=1;i<n;i++){
            if(nums[i].first!=nums[i-1].first)rank++;
            ans[nums[i].second]=rank;
        }
        return ans;
    }
};