class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        int vals=0;
        for(int i=0;i<n;i++){
            vals^=nums[i];
        }
        int maxi=1<<maximumBit;
        maxi--;
        vector<int>res(n);
        vals^=maxi;
        res[0]=vals;
        for(int i=1;i<n;i++){
            vals^=nums[n-i];
            res[i]=vals;
        }
        return res;
    }
};