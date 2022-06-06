class Solution {
public:
    int mod=1e9+7;
    vector<vector<int>>dp;
    int solve(string &s,int i,int k){
        if(i>=s.size())return k==2;
        if(dp[i][k]!=-1)return dp[i][k];
        int ways=0;
        if(k==2){
            if(s[i]=='P')ways=(solve(s,i+1,k)%mod+solve(s,i+1,0)%mod)%mod;
            else ways=solve(s,i+1,1)%mod;
        }
        else{
            ways=solve(s,i+1,k+(s[i]=='S'))%mod;
        }
        return dp[i][k]=ways%mod;
    }
    int numberOfWays(string s) {
        int n=s.size();
        dp.resize(n,vector<int>(3,-1));
        return solve(s,0,0)%mod;
    }
    
};