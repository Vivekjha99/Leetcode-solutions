class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int>dp(n+1,0);
        //dp[i] stores the min ops to make 0..i valid
        int bcnt=0;
        for(int i=0;i<n;i++){
            //case 1 if we get a we can remove all prev b or remove the current a
            if(s[i]=='a')
            dp[i+1]=min(dp[i]+1,bcnt);
            else{
                dp[i+1]=dp[i];
                bcnt++;
                //as b is always favourable at the end
            }
        }
        return dp[n];
        
    }
};