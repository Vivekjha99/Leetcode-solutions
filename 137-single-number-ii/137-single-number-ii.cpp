class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        for(int i=0;i<=31;i++){
            int cnt=0;
            for(auto x:nums){
                if(x&(1<<i))cnt++;
            }
            if(cnt%3)res+=1<<i;
        }
        return res;
    }
};