class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        int n=nums.size();
        int start=0,end=0;
        for(int i=0;i<n;){
            start=i;end=i;
            while(end+1<n && nums[end+1]==nums[end]+1)end++;
            if(start!=end){
                ans.push_back(to_string(nums[start])+"->"+to_string(nums[end]));
            }
            else
                ans.push_back(to_string(nums[start]));
            i=end+1;
        }
        return ans;
    }
};