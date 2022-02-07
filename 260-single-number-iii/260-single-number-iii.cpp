class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long  res=0;
        for(auto x:nums)res^=x;
        //finding the rightmost set bit
        res=(res&(res-1))^res;
        vector<int>ans(2,0);
        for(auto x:nums){
            if(x&res)ans[1]^=x;
            else ans[0]^=x;
        }
        return ans;
    }
};