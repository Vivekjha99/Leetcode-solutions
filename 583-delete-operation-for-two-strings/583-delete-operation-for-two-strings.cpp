class Solution {
public:
    int minDistance(string text1, string text2) {
        int l1=text1.length();
        int l2=text2.length();
        vector<vector<int>>dp(l1+1,vector<int>(l2+1,0));
        for(int i=0;i<=l1;i++){
            for(int j=0;j<=l2;j++){
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
            return l1+l2-2*dp[l1][l2];
    }
};