class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=0,sell=0,n=prices.size()-1;
        //we will find valley and then following peak and so on
        int ans=0;
        int idx=0;
        while(idx<n){
            while(idx<n && prices[idx+1]<=prices[idx])idx++;
            buy=prices[idx];
            while(idx<n &&prices[idx+1]>prices[idx])idx++;
            sell=prices[idx];
            ans+=sell-buy;
        }
        return ans;
    }
};