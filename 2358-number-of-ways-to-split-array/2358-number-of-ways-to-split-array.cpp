class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long>pref(n,0),suff(n,0);
        for(int i=0;i<n;i++){
            pref[i]=1ll*nums[i];
            if(i>0)pref[i]+=pref[i-1];
        }
        for(int i=n-1;i>=0;i--){
            suff[i]=1ll*nums[i];
            if(i<n-1)suff[i]+=suff[i+1];
        }
        int res=0;
        for(int i=0;i<n-1;i++){
            if(pref[i]>=suff[i+1])res++;
        }
        return res;
    }
};