class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>dp(n,0);
        int prev=prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]-prev<0){
                dp[i]=0;
                prev=prices[i];
            }
            else{
                dp[i]=prices[i]-prev;
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};