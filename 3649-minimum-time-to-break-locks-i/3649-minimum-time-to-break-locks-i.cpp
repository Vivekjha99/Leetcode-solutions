class Solution {
public:
    int findMinTime(int mask,int f,int K,vector<int>&str,int n){
        if(mask==(1<<n)-1)return 0;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(!(mask & (1<<i))){
                int time=(str[i]+f-1)/f;
                mini=min(mini,time+findMinTime(mask|1<<i ,f+K,K,str,n));
            }
        }
    return mini;
    }
    int findMinimumTime(vector<int>& strength, int K) {
        sort(strength.begin(),strength.end());
        int n=strength.size();
        return findMinTime(0,1,K,strength,n);
    }
};