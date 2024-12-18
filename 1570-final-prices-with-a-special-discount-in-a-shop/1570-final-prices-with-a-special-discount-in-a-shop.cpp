class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int>ans(n);
        for(int i=n-2;i>=0;i--){
            ans[i]=prices[i];
            for(int j=i+1;j<n;j++){
                if(prices[i]>=prices[j]){
                    ans[i]=prices[i]-prices[j];
                    break;
                }
            }
        }
        ans[n-1]=prices[n-1];
        return ans;
    }
};