class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr=0;
        for(auto x:nums)maxOr|=x;
        int res=0;
        //maxOr =max of all elements
        for(int i=0;i<1<<nums.size();i++){
            int currOr=0;
            for(int j=0;j<nums.size();j++){
                //to check if jth bit is set
                if(i>>j & 1)currOr|=nums[j];
            }
            if(currOr==maxOr)res++;
        }
        return res;
    }
};