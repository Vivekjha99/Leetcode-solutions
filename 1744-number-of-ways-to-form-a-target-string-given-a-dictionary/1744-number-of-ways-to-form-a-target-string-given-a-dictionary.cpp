class Solution {
public:
int mod=1e9+7;
    int countWays(vector<vector<int>>&freq,int i,int j,string &t,vector<vector<int>>&dp){
       if(j==t.size())return 1;
       if(i==freq.size())return 0;//it means columns have ended 
       if(dp[j][i]!=-1)return dp[j][i];
       int notPick=(countWays(freq,i+1,j,t,dp))%mod;
       long long pick=0;
       if(freq[i][t[j]-'a']!=0){
        //current character present at current column
        pick=(1ll*freq[i][t[j]-'a']*countWays(freq,i+1,j+1,t,dp))%mod;;
       }
       return dp[j][i]=(pick+1ll*notPick)%mod;
    }
    int numWays(vector<string>& words, string target) {
        int n=words.size();
        int m=words[0].size();
        //this array will store the frequency of characters in each column
        vector<vector<int>>freq(m,vector<int>(26,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                freq[j][words[i][j]-'a']++;
            }
        }
        //dp[i][j]=no of ways to form prefix of target 0-i by using j cols of the words matrix
        vector<vector<int>>dp(target.size(),vector<int>(m,-1));
        return countWays(freq,0,0,target,dp);
    }
};