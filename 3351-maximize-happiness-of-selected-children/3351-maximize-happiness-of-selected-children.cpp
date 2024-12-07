class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(),happiness.rend());
        long long ans=0;
        for(int i=0;i<k;i++){
            long long res=1LL*happiness[i]-i;
            ans+=res>0?res:0;
        }
        return ans;
    }
};