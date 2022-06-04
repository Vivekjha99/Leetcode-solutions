class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxsum=INT_MIN;
        int currmax=0;int minsum=0,currmin=0;int totalsum=0;
        for(auto x:nums){
            currmax=max(x,currmax+x);
            maxsum=max(maxsum,currmax);
            currmin=min(x,currmin+x);
            minsum=min(currmin,minsum);
            totalsum+=x;
        }
        return maxsum>0?max(maxsum,totalsum-minsum):maxsum;
    }
};