class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int s=0,e=n-1;
        vector<int>temp(nums);
        sort(temp.begin(),temp.end());
        while(s<n && temp[s]==nums[s])s++;
        while(e>s && temp[e]==nums[e])e--;
        return e-s+1;
    }
};