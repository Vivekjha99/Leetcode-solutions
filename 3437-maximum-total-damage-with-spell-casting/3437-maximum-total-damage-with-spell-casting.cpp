class Solution {
public:
#define ll long long 
vector<ll>dp;
    long long maxDamage(map<int,int>&mp,vector<int>&up,int i){
        if(i==up.size())return 0;
        if(dp[i]!=-1)return dp[i];
        ll notTake=maxDamage(mp,up,i+1);
        ll take=0;
        int nextIdx=i+1;
        while(nextIdx<up.size() && up[nextIdx]-up[i]<=2)nextIdx++;
        take=((1ll)*up[i]*mp[up[i]])+maxDamage(mp,up,nextIdx);
        return dp[i]=max(notTake,take);
    }
    long long maximumTotalDamage(vector<int>& power) {
        map<int,int>mp;
        for(auto x:power)mp[x]++;
        vector<int>up;
        for(auto it:mp)up.push_back(it.first);
        int n=up.size();
         dp.resize(up.size()+1,-1);
        // return maxDamage(mp,up,0);
        dp[n]=0;
        dp[n-1]=(1ll*up[n-1]*mp[up[n-1]]);
        for(int i=n-2;i>=0;i--){
            int nidx=lower_bound(up.begin(),up.end(),up[i]+3)-up.begin();
            ll notTake=dp[i+1];
            ll take=(1ll*up[i]*mp[up[i]])+dp[nidx];
            dp[i]=max(take,notTake);
        }
    return dp[0];
    }
};