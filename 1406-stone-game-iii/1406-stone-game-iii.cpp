class Solution {
public:
    string stoneGameIII(vector<int>& stones) {
        int n=stones.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int ans=INT_MIN;
            ans=max(ans,stones[i]-dp[i+1]);
            if(i+1<n)ans=max(ans,stones[i]+stones[i+1]-dp[i+2]);
            if(i+2<n)ans=max(ans,stones[i]+stones[i+1]+stones[i+2]-dp[i+3]);
            dp[i]=ans;
        }
        if(dp[0]>0)return "Alice";
        else if(dp[0]==0)return "Tie";
        else return "Bob";
    }
};