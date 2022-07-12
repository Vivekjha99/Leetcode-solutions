class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        vector<bool>cnt(200005,0);
        for(auto num:nums)cnt[num]=1;
        int ans=0;
        for(int i=1;i<200005;i++){
            int g=0;
            for(int j=i;j<200005;j+=i){
                if(cnt[j])
                    g=__gcd(g,j);
            }
            if(g==i)ans++;
        }
        return ans;
    }
};