class Solution {
public:
    int mod=1e9+7;
    vector<vector<int>>dp;
    int solve(string &s,int i,int k,vector<vector<int>>&dp){
        if(i>=s.size())return k==2;
        if(dp[i][k]!=-1)return dp[i][k];
        int ways=0;
        if(k==2){
            if(s[i]=='P')ways=(solve(s,i+1,k,dp)%mod+solve(s,i+1,0,dp)%mod)%mod;
            else ways=solve(s,i+1,1,dp)%mod;
        }
        else{
            ways=solve(s,i+1,k+(s[i]=='S'),dp)%mod;
        }
        return dp[i][k]=ways%mod;
    }
    int numberOfWays(string s) {
        int n=s.size();
        dp.resize(n,vector<int>(3,-1));
        return solve(s,0,0,dp)%mod;
    }
    
};