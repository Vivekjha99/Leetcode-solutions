class Solution {
public:
int findMaxProfit(vector<vector<int>>&offers,int i,vector<int>&dp){
    if(i==offers.size())return 0;
    if(dp[i]!=-1)return dp[i];
    int notTake=findMaxProfit(offers,i+1,dp);
    //binary search for next offers
    int l=i+1;
    int r=offers.size()-1;
    int res=offers.size();
    while(l<=r){
        int m=l+(r-l)/2;
        if(offers[m][0]>offers[i][1]){
            r=m-1;
            res=m;
        }else{
            l=m+1;
        }
    }
    int take=offers[i][2]+findMaxProfit(offers,res,dp);
    return dp[i]=max(take,notTake);

}
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int m=offers.size();
        sort(offers.begin(),offers.end());
        vector<int>dp(m,-1);
        return findMaxProfit(offers,0,dp);
    }
};