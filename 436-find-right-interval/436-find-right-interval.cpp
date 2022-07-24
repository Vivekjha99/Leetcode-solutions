class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i][0]]=i;
        }
        for(int i=0;i<n;i++){
            auto it=mp.lower_bound(nums[i][1]);
            if(it!=mp.end()){
                ans[i]=it->second;
            }
            else ans[i]=-1;
        }
        return ans;
    }
};