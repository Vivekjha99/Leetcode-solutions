class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int inc=0,exc=0;
        vector<int>cnt(10005,0);
        for(auto num:nums)cnt[num]++;
        inc=cnt[1];
        for(int i=2;i<10005;i++){
            int ninc=exc+cnt[i]*i;
            int nexc=max(inc,exc);
            inc=ninc;
            exc=nexc;
        }
        return max(inc,exc);
    }
};