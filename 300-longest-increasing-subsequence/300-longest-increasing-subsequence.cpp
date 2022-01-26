class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>res;
        for(auto x:nums){
            if(res.empty() || res.back()<x)res.push_back(x);
            else{
                int idx=lower_bound(res.begin(),res.end(),x)-res.begin();
                res[idx]=x;
            }
        }
        return res.size();
    }
};