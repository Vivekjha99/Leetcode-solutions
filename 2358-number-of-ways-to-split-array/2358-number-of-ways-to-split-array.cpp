class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long>suff(n,0);
        for(int i=n-1;i>=0;i--){
            suff[i]=1ll*nums[i];
            if(i<n-1)suff[i]+=suff[i+1];
        }
        int res=0;long long pref=0;
        for(int i=0;i<n-1;i++){
            pref+=nums[i];
            if(pref>=suff[i+1])res++;
        }
        return res;
    }
};