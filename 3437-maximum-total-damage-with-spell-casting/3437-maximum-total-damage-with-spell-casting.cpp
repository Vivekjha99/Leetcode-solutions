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
         dp.resize(up.size(),-1);
        return maxDamage(mp,up,0);
    }
};